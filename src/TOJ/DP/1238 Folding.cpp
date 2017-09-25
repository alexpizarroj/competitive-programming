#include <bits\stdc++.h>
using namespace std;

inline int integerStrSize(int n)
{
	if (n <= 9)
		return 1;
	else if (n < 100)
		return 2;
	return 3;
}

string compact(const string &text)
{
	const int n = text.size();

	vector< vector<int> > repeats(n, vector<int>(n, -1));
	for(int k = 1; k <= n; k++)
		for(int s = n - k; s >= 0; --s)
		{
			int e = s + k - 1;
			int ss = e + 1, ee = ss + k - 1;
			repeats[s][e] = 1;
			if (ee < n)
			{
				bool equalStrings = true;
				for(int i = 0; i < k; i++)
					if (text[s+i] != text[ss+i])
					{
						equalStrings = false;
						break;
					}
				if (equalStrings)
					repeats[s][e] += repeats[ss][ee];
			}
		}

	vector< vector<string> > dp(n, vector<string>(n));
	for(int i = 0; i < n; i++)
		dp[i][i] = text[i];
	for(int k = 2; k <= n; k++)
		for(int s = 0; s + k <= n; s++)
		{
			int e = s + k - 1;
			dp[s][e] = text.substr(s, k);
			for(int i = 0; i < k-1; i++)
			{
				// Smaller solutions merge
				unsigned len = dp[s][s+i].size() + dp[s+i+1][e].size();
				if (dp[s][e].size() > len)
				{
					dp[s][e] = dp[s][s+i] + dp[s+i+1][e];
				}
				// Viable contraction
				if (k%(i+1) == 0 && repeats[s][s+i] >= k/(i+1))
				{
					len = integerStrSize(k/(i+1)) + 2 + dp[s][s+i].size();
					if (dp[s][e].size() > len)
					{
						stringstream ss;
						ss << (k/(i+1)) << '(';
						ss << dp[s][s+i] << ')';
						dp[s][e] = ss.str();
					}
				}
			}
		}

	return dp[0][n-1];
}

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	string text;
	while (cin >> text)
		cout << compact(text) << '\n';
	return 0;
}
