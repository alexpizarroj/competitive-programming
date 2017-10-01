#include <bits\stdc++.h>
using namespace std;

vector< vector<int> > G;
vector<int> timeNeeded;

void dfs(int u, int parent)
{
	vector<int> times;
	timeNeeded[u] = 0;
	for(const int v : G[u])
	{
		if (v == parent)
			continue;
		dfs(v, u);
		times.push_back(timeNeeded[v]);
	}

	sort(times.begin(), times.end(), greater<int>());
	for(int i = 1; i <= (int)times.size(); i++)
	{
		timeNeeded[u] = max(times[i-1] + i, timeNeeded[u]);
	}
}

int solve(int n)
{
	G.assign(n, vector<int>());
	for(int i = 0; i < n; i++)
	{
		int j;
		while (cin >> j, j)
		{
			--j;
			G[j].push_back(i);
			G[i].push_back(j);
		}
	}

	int root;
	cin >> root;
	--root;
	timeNeeded.assign(n, -1);
	dfs(root, -1);

	return timeNeeded[root];
}

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	while (cin >> n)
		cout << solve(n) << '\n';
	return 0;
}
