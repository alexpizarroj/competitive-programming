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

const int inf = int(1e9+7);
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef long long       i64;
typedef vector<i64>     vi64;

vector<vi> g, gt;
stack<int> S;
int n; vi scc;

void scc_dfs(const vector<vi> &g, int u, bool addToStack = false)
{
    forn(i,g[u].size())
    {
        int v = g[u][i];
        if ( scc[v] == inf )
        {
            scc[v] = scc[u];
            scc_dfs(g, v, addToStack);
        }
    }
    if ( addToStack ) S.push(u);
}

int kosaraju()
{
    int ans = 0;
    scc.assign(n, inf);
    forn(u,n) if ( scc[u] == inf )
    {
        scc[u] = true;
        scc_dfs(g, u, true);
    }
    scc.assign(n, inf);
    while ( !S.empty() )
    {
        int u = S.top(); S.pop();
        if ( scc[u] != inf ) continue;
        scc[u] = ans++;
        scc_dfs(gt, u);
    }
    return ans;
}

int main()
{
    int tc;
    cin >> tc;
    while ( tc-- )
    {
        int m;
        scanf("%d %d", &n, &m);
        g.assign(n, vi());
        gt.assign(n, vi());
        forn(i,m)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            --x, --y;
            g[x].pb(y);
            gt[y].pb(x);
        }
        
        int nc = kosaraju();
        vi used(nc, false);
        forn(u,n)
        {
            forn(i,g[u].size())
            {
                int v = g[u][i];
                if ( scc[v] != scc[u] && !used[scc[v]] )
                {
                    used[ scc[v] ] = true;
                    --nc;
                }
            }
        }
        printf("%d\n", nc);
    }
    
    return 0;
}