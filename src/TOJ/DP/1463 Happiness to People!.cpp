#include <bits\stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
vi A, visited, dp;
vector<ii> choice;
int n, m, ans, ans_v;
vector<vi> g, we;

void dfs(const int u, const int parent)
{
	int best[2] = {0, 0};
	for(int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if (visited[v])
			continue;

		visited[v] = true;
		dfs(v, u);
		dp[v] += we[u][i];
		
		if (best[0] < dp[v])
		{
			best[1] = best[0];
			choice[u].second = choice[u].first;
			best[0] = dp[v];
			choice[u].first = v;
		}
		else if (best[1] < dp[v])
		{
			best[1] = dp[v];
			choice[u].second = v;
		}
	}

	int cand = A[u] + best[0] + best[1];
	if (cand > ans)
	{
		ans = cand;
		ans_v = u;
	}
	dp[u] = A[u] + best[0];
}

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n >> m)
	{
		A.resize(n+1);
		g.assign(n+1, vi());
		we.assign(n+1, vi());
		for(int i = 1; i <= n; i++)
			cin >> A[i];
		while (m--)
		{
			int a, b, c;
			cin >> a >> b >> c;
			g[a].push_back(b);
			g[b].push_back(a);
			we[a].push_back(c);
			we[b].push_back(c);
		}
		visited.assign(n+1, false);

		ans = -1;
		dp.assign(n+1, 0);
		choice.assign(n+1, ii(-1, -1));
		for(int u = 1; u <= n; u++)
			if (!visited[u])
			{
				visited[u] = true;
				dfs(u, -1);
			}
		assert(ans >= 0 && ans_v >= 1 && ans_v <= n);

		vi solution;
		for(int u = choice[ans_v].first; u != -1; u = choice[u].first)
			solution.push_back(u);
		reverse(begin(solution), end(solution));
		solution.push_back(ans_v);
		for(int u = choice[ans_v].second; u != -1; u = choice[u].first)
			solution.push_back(u);
		
		cout << ans << '\n';
		cout << solution.size() << '\n';
		for(int v : solution)
			cout << v << " ";
		cout << '\n';
	}
	return 0;
}
