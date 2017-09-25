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

const int maxp = 100005;
const int rtmaxp = (int)sqrt(maxp) + 1;
vi xs[maxp];

inline bool exists(int x, int y)
{
    if ( x >= maxp ) return false;
    return binary_search(all(xs[x]), y);
}

int main()
{
    int n;
    while ( cin >> n )
    {
        forn(i,maxp) xs[i].clear();
        forn(i,n)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            xs[x].pb(y);
        }
        forn(i,maxp) sort(all(xs[i]));
        
        i64 ans = 0;
        forn(x,maxp)
        {
            if ( xs[x].size() < rtmaxp )
            {
                forn(i,xs[x].size()) fore(j,i+1,xs[x].size()-1)
                {
                    int d = xs[x][j] - xs[x][i];
                    if ( exists(x+d, xs[x][i]) && exists(x+d, xs[x][j]) ) ++ans;
                }
            }
            else
            {
                fore(xx,x+1,maxp-1) forn(i,xs[xx].size())
                {
                    int yy = xs[xx][i], d = xx - x;
                    if ( exists(x, yy) && exists(x, yy+d) && exists(xx,yy+d) ) ++ans;
                }
            }
        }
        cout << ans << endl;
    }
	
    return 0;
}
