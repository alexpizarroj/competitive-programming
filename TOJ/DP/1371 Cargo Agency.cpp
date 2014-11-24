#include <bits\stdc++.h>
using namespace std;

vector< vector<int> > adj, we;
vector<int> cnt;
vector<long long> sum, dp;

void dfs(const int u, const int parent)
{
	cnt[u] = 1;
	sum[u] = 0;
	dp[u] = 0;

	for(int i = 0; i < (int)adj[u].size(); i++)
	{
		int v = adj[u][i], cost = we[u][i];
		if (v == parent)
			continue;

		dfs(v, u);
		cnt[u] += cnt[v];
		sum[u] += (cost * cnt[v]) + sum[v];
		dp[u] += dp[v];
	}

	for(int i = 0; i < (int)adj[u].size(); i++)
	{
		int v = adj[u][i], cost = we[u][i];
		if (v == parent)
			continue;

		long long cursum = (cost * cnt[v]) + sum[v];
		dp[u] += cursum * 2 * (cnt[u] - cnt[v]);
	}
}

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	while (cin >> n)
	{
		adj.assign(n, vector<int>());
		we.assign(n, vector<int>());
		for(int i = 0; i < n-1; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			--a, --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
			we[a].push_back(c);
			we[b].push_back(c);
		}

		cnt.resize(n);
		sum.resize(n);
		dp.resize(n);
		dfs(0, -1);

		double ans = ((double)dp[0] / ((long long)n * (n-1)));
		cout << fixed << setprecision(4) << ans << '\n';
	}
	return 0;
}
