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
typedef pair<int,ii>    iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef long long       i64;
typedef vector<i64>     vi64;

const int MAXN = 100005;
int pa[MAXN], sz[MAXN], we[MAXN];

int getSet(int u)
{
    if ( pa[u] == u ) return u;
    return pa[u] = getSet(pa[u]);
}

int main()
{
    int n, m;
    while ( cin >> n >> m )
    {
        forn(i,n)
        {
            scanf("%d", we+i);
            pa[i] = i, sz[i] = 1;
        }
        vector<iii> elist;
        forn(i,m)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            --x, --y;
            elist.pb( make_pair(min(we[x], we[y]), ii(x,y)) );
        }
        sort(all(elist), greater<iii>());
        double s = 0;
        forn(x,elist.size())
        {
            int u = getSet(elist[x].second.first);
            int v = getSet(elist[x].second.second);
            if ( u == v ) continue;
            s += i64(sz[u]) * sz[v] * elist[x].first;
            pa[u] = v, sz[v] += sz[u];
        }
        double d = double((i64)n*(n-1));
        printf("%.8lf\n", 2*(s/d));
    }
    return 0;
}
