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
typedef vector<ii>      vii;
typedef long long       i64;
typedef vector<i64>     vi64;

int main()
{
    int n, m;
    while ( cin >> n >> m )
    {
        vi we(n);
        vii nodewe(n);
        vector<vi> g(n, vi());
        forn(i,n)
        {
            scanf("%d", &we[i]);
            nodewe[i].first = we[i];
            nodewe[i].second = i;
        }
        forn(i,m)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            --x, --y;
            g[x].pb(y);
            g[y].pb(x);
        }
        vi taken(n, false);
        sort(all(nodewe));
        i64 ans = 0;
        forn(i,n)
        {
            int u = nodewe[i].second;
            taken[u] = true;
            forn(j,g[u].size())
            {
                int v = g[u][j];
                if ( taken[v] ) ans += we[v];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
