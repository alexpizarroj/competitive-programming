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
#include <cassert>
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
typedef pair<int,int> ii;
typedef vector<int> vi;

// Graph Structure
// 0 -> (idcnt-1):       non-water in vertices
// idcnt -> (2*idcnt-1): non-water out vertices
// 2*idcnt:              source
// 2*idcnt+1:            sink
vector<vi> adjlist;
int res[2000][2000];
int n, s, t, idcnt;
// Graph Modeling
const int dx[] = {0,  0, 1, -1};
const int dy[] = {1, -1, 0,  0};
map<char, int> symbol_cap;
int posToId[2000][2000];
char maze[40][40];

int getout(int u) { return u + idcnt; }

int find_path()
{
    vi visited(n, 0), from(n, -1);
    queue<int> q; int u, v, f;

    q.push(s); visited[s] = true;
    while ( !visited[t] && !q.empty() )
    {
        u = q.front(); q.pop();
        for(int i = 0; i < (int)adjlist[u].size(); ++i)
        {
            v = adjlist[u][i];
            if ( res[u][v] > 0 && !visited[v] )
            {
                from[v] = u;
                q.push(v); visited[v] = true;
                if ( v == t ) { break; }
            }
        }
    }

    f = INF;
    if ( visited[t] )
    {
        for(v = t; from[v] > -1; v = from[v])
            f = min(res[from[v]][v], f);
        for(v = t; from[v] > -1; v = from[v])
            u = from[v], res[u][v] -= f, res[v][u] += f;
    }

    return (f == INF ? 0 : f);
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
    int x, y, p, u, v;
    vi people, wood;
    vector<char> idToSymbol;

    symbol_cap['*'] = 1, symbol_cap['~'] = 0;
    symbol_cap['.'] = 1, symbol_cap['@'] = INF;
    symbol_cap['#'] = INF;
    memset(posToId, -1, sizeof posToId);

	while ( scanf("%d %d %d", &x, &y, &p) != EOF )
	{
	    getchar();
        fup(i,0,x) gets(maze[i]);

        // Vertex naming
        idcnt = 0; people.clear();
        wood.clear(); idToSymbol.clear();
        fup(i,0,x) fup(j,0,y) if ( maze[i][j] != '~' )
        {
            if ( maze[i][j] == '*' ) people.PB(idcnt);
            if ( maze[i][j] == '#' ) wood.PB(idcnt);
            posToId[i][j] = idcnt++; idToSymbol.PB(maze[i][j]);
        }

        // Graph basics init & in-out vertices init
        n = 2*idcnt+2;
        s = n-2, t = n-1;
        adjlist.assign(n, vi());
        memset(res, 0, sizeof res);
        for(u = 0; u < idcnt; u++)
        {
            v = getout(u);
            adjlist[u].PB(v); adjlist[v].PB(u);
            res[u][v] = symbol_cap[ idToSymbol[u] ];
        }

        // Interconnection
        fup(i,0,x) fup(j,0,y) if ( maze[i][j] != '~' )
        {
            int r, c;
            u = getout(posToId[i][j]); // out vertex
            fup(k,0,4)
            {
                r = i + dx[k], c = j + dy[k];
                if ( r < 0 || r >= x || c < 0 || c >= y || maze[r][c] == '~' ) continue;
                v = posToId[r][c]; // in vertex

                adjlist[u].PB(v); adjlist[v].PB(u);
                res[u][v] = INF;
            }
        }

        // Source -> People
        foreach(it, people)
        {
            u = *it; // person in vertex
            adjlist[s].PB(u); adjlist[u].PB(s);
            res[s][u] = 1;
        }

        // Wood -> Sink
        foreach(it, wood)
        {
            u = getout(*it); // wood out vertex
            adjlist[u].PB(t); adjlist[t].PB(u);
            res[u][t] = p;
        }

        // Max flow and output
        printf("%d\n", maxflow());
	}

    return 0;
}
