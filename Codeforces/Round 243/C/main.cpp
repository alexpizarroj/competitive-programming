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
typedef long long       i64;
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<i64>     vi64;

const int maxv = 100005, maxj = 350;
int a[maxv], dp[maxj][maxv];
vi b[maxv];

int main()
{
    int n, m, s, e;
    
    while ( cin >> n >> m >> s >> e )
    {
        forn(i,n)
        {
            scanf("%d", &a[i]);
        }
        forn(i,maxv) b[i].clear();
        forn(i,m)
        {
            int x;
            scanf("%d", &x);
            b[x].pb(i);
        }
        
        int ans = 0;
        forn(i,n)
        {
            dp[1][i] = b[a[i]].empty() ? inf : b[a[i]][0];
            if ( e + i+1 + dp[1][i]+1 <= s ) ans = 1;
        }
        fore(j,2,maxj-1)
        {
            int mn = inf;
            forn(i,n)
            {
                vi::iterator pos = upper_bound(all(b[a[i]]), mn);
                dp[j][i] = ( pos == b[a[i]].end() ? inf : *pos );
                if ( j*e + i+1 + dp[j][i]+1 <= s ) ans = j;
                mn = min(mn, dp[j-1][i]);
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
