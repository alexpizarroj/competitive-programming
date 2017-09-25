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
    int n, m, a[105][105];
    
    while ( cin >> n >> m )
    {
        forn(i,n) forn(j,m) cin >> a[i][j];
        while ( n%2 == 0 )
        {
            bool doable = true;
            forn(r,n/2) forn(c,m) if ( a[r][c] != a[n-r-1][c] ) doable = false;
            if ( doable ) n >>= 1; else break;
        }
        cout << n << endl;
    }
	
    return 0;
}
