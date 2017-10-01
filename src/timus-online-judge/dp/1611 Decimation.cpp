#include <bits\stdc++.h>
using namespace std;

const int inf = int(1e9) + 7;
int dp[10005][55][15], nDrivers, nDodgers;
string str;

int f(int t, int k, int s)
{
	int &ans = dp[t][k][s];
	if (ans == -1)
	{
		if (t == nDrivers-1)
			ans = (s == 0 && str[t] == '1' ? 1 : 0);
		else
		{
			ans = (s == 0 && str[t] == '1' ? 1 : 0);
			ans += f(t+1, k, (s+9)%10);
			if (k >= 1)
			{
				int cand = (s == 0 ? 1 : 0) + f(t, k-1, (s+9)%10);
				if (cand < ans)
					ans = cand;
			}
		}
	}
	return ans;
}

void backtrack(int t, int k, int s)
{
	vector<int> pos;
	int p = 1;

	while (t < nDrivers)
	{
		if (t == nDrivers-1)
		{
			t += 1;
		}
		else
		{
			int cand1 = (s == 0 && str[t] == '1' ? 1 : 0);
			cand1 += f(t+1, k, (s+9)%10);

			if (f(t, k, s) != cand1)
			{
				pos.push_back(p);
				k -= 1;
			}
			else
			{
				t += 1;
			}
		}
		s = (s+9)%10;
		p += 1;
	}
	
	cout << pos.size();
	for(int i = 0; i < (int)pos.size(); i++)
		cout << " " << pos[i];
	cout << "\n";
}

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> nDrivers >> nDodgers >> str)
	{
		memset(dp, -1, sizeof dp);
		cout << f(0, nDodgers, 9) << '\n';
		backtrack(0, nDodgers, 9);
	}
	return 0;
}
