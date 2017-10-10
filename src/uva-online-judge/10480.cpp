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
#include <bitset>
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define MSB(n) ( n <= 0 ? 0 : int(floor(log(n)/log(2))) )
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
const int INF = 1e8;

vector<vi> adjList;
int res[60][60];
int n, source, sink;

int find_path()
{
    queue<int> q;
    vi visited(n+1, 0), from(n+1, -1);
    bool path_found; int u, v, f;

    path_found = false;
    q.push(source); visited[source] = true;
    while ( !path_found && !q.empty() )
    {
        u = q.front(); q.pop();
        for(int i = 0; i < (int)adjList[u].size(); ++i)
        {
            v = adjList[u][i];
            if ( res[u][v] > 0 && !visited[v] )
            {
                from[v] = u;
                if ( v == sink ) { path_found = true; break; }
                q.push(v); visited[v] = true;
            }
        }
    }

    f = INF;
    if ( path_found )
    {
        for(v = sink; from[v] > -1; v = from[v])
            f = min(f, res[from[v]][v]);
        for(v = sink; from[v] > -1; v = from[v])
            u = from[v], res[u][v] -= f, res[v][u] += f;
    }

    return (f == INF ? 0 : f);
}

int max_flow()
{
    int mf = 0, d;
    while ( (d = find_path()) ) mf += d;
    return mf;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int m, u, v, cost, mf;
	queue<int> q; vi visited;
	vector<ii> cut;

    source = 1, sink = 2;
	while ( scanf("%d %d", &n, &m), n || m )
	{
	    memset(res, 0, sizeof res);
	    adjList.assign(n+1, vi());
	    while ( m-- )
	    {
            scanf("%d %d %d", &u, &v, &cost);
            adjList[u].PB(v); adjList[v].PB(u);
            res[u][v] = res[v][u] = cost;
	    }
        mf = max_flow(); cut.clear();
        visited.assign(n+1, 0);
        q.push(source); visited[source] = true;
        while ( !q.empty() )
        {
            u = q.front(); q.pop();
            for(int i = 0; i < (int)adjList[u].size(); ++i)
            {
                v = adjList[u][i];
                if ( res[u][v] > 0 && !visited[v] )
                    q.push(v), visited[v] = true;
                else if ( res[u][v] == 0 )
                    cut.PB( ii(u, v) );
            }
        }
        cost = 0;
        for(int i = 0; i < (int)cut.size(); ++i)
        {
            if ( !visited[ cut[i].second ] )
            {
                u = cut[i].first, v = cut[i].second;
                cost += res[v][u]/2;
                printf("%d %d\n", u, v);
            }
        }
        puts("");

        assert(mf == cost);
	}

    return 0;
}
