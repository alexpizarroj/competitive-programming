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

const int INF = int(1E9+7);
const double EPS = 1e-6;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int MAX = 110;
int res[MAX][MAX];
vector<vi> adjlist;
int m, n, s, t;

int find_path()
{
    vi from(n,-1), visited(n,0);
    queue<int> q; int u, v, f;

    q.push(s); visited[s] = true;
    while ( !visited[t] && !q.empty() )
    {
        u = q.front(); q.pop();
        fup(i,0,adjlist[u].size())
        {
            v = adjlist[u][i];
            if ( res[u][v] > 0 && !visited[v] )
            {
                from[v] = u;
                q.push(v); visited[v] = true;
                if ( v == t ) break;
            }
        }
    }

    f = INF;
    if ( visited[t] )
    {
        for(u = t; from[u] > -1; u = from[u])
            f = min(f, res[from[u]][u] );
        for(u = t; from[u] > -1; u = from[u])
            v = from[u], res[v][u] -= f, res[u][v] += f;
    }

    return ( f == INF ? 0 : f);
}

int maxflow()
{
    int mf = 0, d;
    while ( (d = find_path()) ) mf += d;
    return mf;
}

inline int getv(int u)
{
    if ( u == 1 || u == m ) return u;
    return u + (u < m ? m-1 : 1-m);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
	int w, u, v, u_out, v_out, cap;

	while ( scanf("%d %d", &m, &w), m || w )
	{
        n = 2*(m-1)+1, s = 1, t = m;
        memset(res, 0, sizeof res);
        adjlist.assign(n, vi());
        fup(i,0,m-2)
        {
            scanf("%d %d", &u, &cap); // machine, machine capacity
            u_out = getv(u);

            // u -> u_out
            adjlist[u].PB(u_out); adjlist[u_out].PB(u);
            res[u][u_out] = cap;
        }
        fup(i,0,w)
        {
            scanf("%d %d %d", &u, &v, &cap);
            u_out = getv(u); v_out = getv(v);

            // u -> v
            adjlist[u_out].PB(v); adjlist[v].PB(u_out);
            res[u_out][v] = cap;

            // v -> u
            adjlist[v_out].PB(u); adjlist[u].PB(v_out);
            res[v_out][u] = cap;
        }
        printf("%d\n", maxflow());
	}

    return 0;
}
