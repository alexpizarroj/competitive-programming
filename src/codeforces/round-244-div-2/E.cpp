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

int main()
{
    vector<int> vec;
    int n, m;
    
    while ( cin >> n >> m )
    {
        vec.resize(n);
        forn(i,n)
        {
            scanf("%d", &vec[i]);
        }
        if ( m > n ) m = n;
        
        i64 ans = 1e18, cand;
        fore(i,1,m)
        {
            int nle = (i-1), nri = n-i, len;
            nle = (nle/m) + (nle%m > 0 ? 1 : 0);
            nri = (nri/m) + (nri%m > 0 ? 1 : 0);
            len = nle + nri + 1;
            
            int p = (len/2) + (len&1), q;
            if ( p == 1 ) q = 0;
            else // if ( p >= 2 )
            {
                int x = 1 + (i > 1 ? 1 : 0);
                q = (i-1) + (p-x)*m;
            }
            
            cand = 0;
            for(int j = n-1; j > q; j -= m)
            {
                cand += vec[j] - vec[q];
            }
            for(int j = 0; j < q; j += m)
            {
                cand += vec[q] - vec[j];
            }
            
            if ( ans > cand ) ans = cand;
        }
        
        cout << 2*ans << endl;
    }
	
    return 0;
}
 