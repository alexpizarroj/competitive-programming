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

int msb(int n)
{
    assert(n >= 1);
    
    int res = 0;
    while ( n > 0 )
    {
        n >>= 1;
        ++res;
    }
    return (1<<(res-1));
}

int bitcount(int n)
{
    int res = 0;
    while ( n > 0 )
    {
        res += (n&1);
        n >>= 1;
    }
    return res;
}

int main()
{
    int tc, a, b, k, kp;
    int comb[35][35];
    
    fore(c,0,30) fore(d,0,c)
    {
        if ( d == 0 || d == c ) comb[c][d] = 1;
        else
        {
            comb[c][d] = comb[c-1][d-1] + comb[c-1][d];
        }
    }
    
    // 536870912, hasta 29 bits encendidos
    // 8 * 10^7, valor de peor combinacion generada
    
    cin >> tc;
    fore(caso,1,tc)
    {
        printf("Case #%d: ", caso);
        cin >> a >> b >> k;
        if ( a > b ) swap(a,b);
        
        i64 ans = 0;
        if ( k >= b )
        {
            ans = (i64)a * b;
        }
        else if ( k <= a )
        {
            ans = (i64)k * k;
        }
        else // if ( max(a,b) > k )
        {
            if ( a > b ) swap(a, b);
            kp = msb(k)-1;
            //printf("Subproblem till %d\n", kp);
            //printf("Bitcount is %d\n", bitcount(kp));
            for(int i = 1, bits = bitcount(kp); i <= bits; i++)
            {
                ans += comb[bits][i] * ( 1 << (bits-i) );
            }
            // Falta
        }
        cout << ans << endl;
    }
	
    return 0;
}
