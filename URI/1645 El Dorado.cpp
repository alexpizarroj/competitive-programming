#include <iostream>
#include <vector>
using namespace std;

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, k;
	while (cin >> n >> k, n || k)
	{
		vector< vector<long long> > dp(n, vector<long long>(k+1, 0));
		vector<int> value(n);
		for(int i = 0; i < n; i++)
		{
			cin >> value[i];
			dp[i][1] = 1;
		}

		for(int sz = 2; sz <= k; sz++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < i; j++)
					if (value[j] < value[i])
						dp[i][sz] += dp[j][sz-1];
		
		long long ans = 0;
		for(int i = 0; i < n; i++)
			ans += dp[i][k];
		cout << ans << '\n';
	}
	
	return 0;
}
