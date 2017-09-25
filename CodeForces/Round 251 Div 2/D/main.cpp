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

vi devu, bro;
vector<i64> devusum, brosum;
i64 solve(int blim)
{
    i64 res = 0;
    int p;
    
    // Devu's array
    p = distance(
        devu.begin(),
        lower_bound(devu.begin(), devu.end(), blim)
    ) - 1;
    if ( 1 <= p && p < (int)devu.size() )
    {
        int q = p; p = 1;
        res += i64(q-p+1)*blim - (devusum[q] - devusum[p-1]);
        //printf("\t Inside Devu, from %d to %d\n", p, q);
    }
    // Brother's array
    p = distance(
        bro.begin(), 
        upper_bound(bro.begin(), bro.end(), blim)
    );
    if ( 1 <= p && p < (int)bro.size() )
    {
        int q = (int)bro.size() - 1;
        res += (brosum[q] - brosum[p-1]) - i64(q-p+1)*blim;
        //printf("\t Inside Bro, from %d to %d\n", p, q);
    }
    //cout << "Tried for " << blim << ", I need " << res << " steps" << endl;
    
    return res;
}

int main()
{
    int n, m;
    while ( cin >> n >> m )
    {
        devu.clear(); bro.clear();
        devu.pb(0), bro.pb(0);
        fore(i,1,n)
        {
            int a;
            scanf("%d", &a);
            devu.pb(a);
        }
        fore(i,1,m)
        {
            int b;
            scanf("%d", &b);
            bro.pb(b);
        }
        
        sort(all(devu));
        devusum.resize(devu.size()), devusum[0] = 0;
        fore(i,1,n) devusum[i] = devusum[i-1] + devu[i];
        
        sort(all(bro));
        brosum.resize(bro.size()), brosum[0] = 0;
        fore(i,1,m) brosum[i] = brosum[i-1] + bro[i];
        
        i64 ans = 9223372036854775807LL;
        fore(i,1,n) ans = min(ans, solve(devu[i]));
        fore(i,1,m) ans = min(ans, solve(bro[i]));
        cout << ans << endl;
    }
    return 0;
}
