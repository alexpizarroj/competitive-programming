#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
const int inf = int(1e9) + 7;
int distMat[2005][2005];

bool bfs_dist_check(const vector< vector<ii> > &graph, int u)
{
	int n = graph.size(), root = u;
	vi dist(n, inf);
	queue<int> q;
	q.push(u);
	dist[u] = 0;
	while ( !q.empty() )
	{
		u = q.front();
		q.pop();
		for(int i = 0; i < (int)graph[u].size(); i++)
		{
			int v = graph[u][i].first, u_v_we = graph[u][i].second;
			if ( dist[v] != inf ) continue;
			dist[v] = dist[u] + u_v_we;
			q.push(v);
		}
	}
	for(int i = 0; i < n; i++)
		if ( distMat[root][i] != dist[i] )
			return false;
	return true;
}

void mst(int n, vector< vector<ii> > &graph)
{
	vector<bool> taken(n, false);
	vi parent(n, -1);
	vi distValue(n, inf);
	int next = 0;
	graph.assign(n, vector<ii>());
	distValue[next] = 0;
	taken[next] = true;
	for(int it = 0; it < n; it++)
	{
		int u = next, value = distValue[next];
		// If it's not the root, add it to the graph with its corresponding edge
		if ( parent[u] != -1 )
		{
			int v = parent[u];
			graph[u].push_back( ii(v, distMat[u][v]) );
			graph[v].push_back( ii(u, distMat[u][v]) );
		}
		// Relax all neighbours not yet taken
		// Also, we'll calculate which vertex should be next
		value = inf;
		for(int i = 0; i < n; i++)
		{
			if ( taken[i] ) continue;
			if ( distValue[i] > distMat[u][i] )
			{
				distValue[i] = distMat[u][i];
				parent[i] = u;
			}
			if ( distValue[i] < value )
			{
				value = distValue[i];
				next = i;
			}
		}
		// Mark the next vertex as taken
		taken[next] = true;
	}
}

string solve(int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &distMat[i][j]);
	// There should be no self-loops in a Tree
	for(int i = 0; i < n; i++)
		if ( distMat[i][i] != 0 )
			return "NO";
	// The distance matrix should be simetric
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if ( distMat[i][j] != distMat[j][i] )
				return "NO";
	// Every value which is not in the main diagonal should be > 0
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			if ( distMat[i][j] == 0 )
				return "NO";
	// MST
	vector< vector<ii> > graph;
	mst(n, graph);
	// Distance checking
	for(int i = 0; i < n; i++)
		if ( bfs_dist_check(graph, i) == false )
			return "NO";
	
	return "YES";
}

int main()
{
	int n;
	while ( cin >> n )
		cout << solve(n) << endl;
	return 0;
}