#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <iostream>
#define PB push_back
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
using namespace std;

#define UNSET -1
#define WHITE 1
#define BLUE 2
#define RED 3
typedef pair<int,int> AdjPair;
typedef vector<AdjPair> AdjVec;

vector< AdjVec > adj;
vector<int> color;
int colorAdj[4][2] = { {0,0}, {BLUE,RED}, {WHITE,RED}, {WHITE,BLUE} };

void dfs(int u)
{
    fup(i,0,adj[u].size())
    {
        int a = adj[u][i].first, b = adj[u][i].second;
        if ( color[a] != UNSET ) continue;
        
        color[a] = colorAdj[ color[u] ][0];
        color[b] = colorAdj[ color[u] ][1];
        dfs(a); dfs(b);
    }
}

int main()
{
    int n, m, a, b, c;
    
    while ( ~scanf("%d%d", &n, &m) )
    {
        adj.assign(n + 1, AdjVec());
        while ( m-- )
        {
            scanf("%d%d%d", &a, &b, &c);
            adj[a].PB( AdjPair(b, c) );
            adj[b].PB( AdjPair(a, c) );
            adj[c].PB( AdjPair(a, b) );
        }
        
        color.assign(n + 1, UNSET);
        fupi(u,1,n) if( color[u] == UNSET )
        {
            color[u] = WHITE;
            dfs(u);
        }
        
        fupi(u,1,n) printf("%d ", color[u]);
        puts("");
    }
    
    return 0;
}
