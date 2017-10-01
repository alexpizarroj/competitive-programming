#include <ctime>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <numeric>

#define pb              push_back
#define all(a)          (a).begin(), (a).end()
#define forn(i, n)      for(int i = 0; i < int(n); ++i)
#define fore(i, a, b)   for(int i = int(a); i <= int(b); ++i)
#define foreach(it, a)  for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)

using namespace std;

const int inf = 1000000007LL;
const long long inf64 = 1000000000000000007LL;
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef long long       i64;
typedef vector<i64>     vi64;

struct Edge
{
	Edge() {}
	Edge(int a, long long b, bool c) :
		v(a), we(b), trainEdge(c) { }
	int v;
	long long we;
	bool trainEdge;
	bool operator<(const Edge &rhs) const
	{
		if ( we != rhs.we )
			return ( we < rhs.we );
		if ( trainEdge != rhs.trainEdge )
			return ( !trainEdge );
		return v < rhs.v;
	}
};

// Returns the amount of train tracks used
int dijkstra(const vector< vector<Edge> > &g, const int start)
{
	int ans = 0;
	set<Edge> pq;
	vector<long long> dist(g.size(), inf64);
	vector<bool> proc(g.size(), false);
	
	dist[start] = 0;
	pq.insert( Edge(start, dist[start], 0) );
	while ( !pq.empty() )
	{
		Edge e = *pq.begin();
		const int u = e.v;
		pq.erase(pq.begin());
		if ( proc[u] ) continue;
		ans += e.trainEdge;
		forn(i,g[u].size())
		{
			int v = g[u][i].v, v_we = g[u][i].we;
			if ( dist[u] + v_we <= dist[v] )
			{
				dist[v] = dist[u] + v_we;
				pq.insert( Edge(v, dist[v], g[u][i].trainEdge) );
			}
		}
		proc[u] = true;
	}
	return ans;
}

int main()
{
    int n, m, k;
	while ( cin >> n >> m >> k )
	{
		vector< vector<Edge> > g(n, vector<Edge>());
		forn(i,m)
		{
			int u, v, x;
			scanf("%d %d %d", &u, &v, &x);
			--u, --v;
			g[u].pb( Edge(v,x,0) );
			g[v].pb( Edge(u,x,0) );
		}
		forn(i,k)
		{
			int s, y;
			scanf("%d %d", &s, &y);
			--s;
			g[0].pb( Edge(s,y,1) );
			g[s].pb( Edge(0,y,1) );
		}
		cout << ( k - dijkstra(g, 0) ) << endl;
	}
    return 0;
}
