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
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define MSB(n) ( n <= 0 ? 0 : int(floor(log(n)/log(2))) )
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;

const int INF = int(1e9+7);
const double EPS = 1e-6;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int MAX = 110;
vector<vi> adjlist;
int res[MAX][MAX];
int n, s, t;

int find_path()
{
    vi from(n+1, -1), visited(n+1, 0);
    queue<int> q; bool found = false;
    int u, v, f;

    q.push(s); visited[s] = true;
    while ( !found && !q.empty() )
    {
        u = q.front(); q.pop();
        fup(i,0,adjlist[u].size())
        {
            v = adjlist[u][i];
            if ( res[u][v] > 0 && !visited[v] )
            {
                from[v] = u;
                q.push(v); visited[v] = true;
                if ( v == t ) { found = true; break; }
            }
        }
    }

    f = INF;
    if ( found )
    {
        for(u = t; from[u] > -1; u = from[u])
            f = min(f, res[from[u]][u] );
        for(u = t; from[u] > -1; u = from[u])
            v = from[u], res[v][u] -= f, res[u][v] += f;
    }

    return ( f == INF ? 0 : f );
}

int maxflow()
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

	int c, u, v, bw, caseNo = 1;

	while ( scanf("%d", &n), n > 0 )
	{
        scanf("%d %d %d", &s, &t, &c);
        memset(res, 0, sizeof res);
        adjlist.assign(n+1, vi());
        fup(i,0,c)
        {
            scanf("%d %d %d", &u, &v, &bw);
            if ( res[u][v] == 0 )
            {
                adjlist[u].PB(v); adjlist[v].PB(u);
            }
            res[u][v] += bw, res[v][u] += bw;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", caseNo++, maxflow());
	}

    return 0;
}
