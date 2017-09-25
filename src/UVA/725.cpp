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
    vii res;
    int n, caseno = 1;
    while ( scanf("%d", &n), n )
    {
        if ( caseno > 1 ) puts("");
        // Computation
        bool seen[10];
        res.clear();
        forn(a,10) forn(b,10) forn(c,10) forn(d,10) forn(e,10)
        {
            int dem = a*10000 + b*1000 + c*100 + d*10 + e;
            if ( dem == 0 ) continue;
            int num = (n * dem)%100000;
            if ( num / dem != n ) continue;
            
            int x = num, y = dem, valid = 1;
            memset(seen, 0, sizeof seen);
            forn(i,5)
            {
                if ( seen[x%10] ) { valid = 0; break; }
                seen[x%10] = true;
                x /= 10;
                if ( seen[y%10] ) { valid = 0; break; }
                seen[y%10] = true;
                y /= 10;
            }
            if ( valid ) res.pb( ii(num, dem) );
        }
        // Output
        if ( res.size() == 0 ) 
        {
            printf("There are no solutions for %d.\n", n);
        }
        else
        {
            forn(i,res.size())
            {
                printf("%05d / %05d = %d\n", res[i].first, res[i].second, n);
            }
        }
        caseno++;
    }
    return 0;
}
