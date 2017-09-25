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
typedef vector<i64>     vi64;
typedef pair<int,int>   ii;
typedef vector<int>     vi;

int mat[105][105], n, m;

int countr(int r)
{
    int res = 0;
    forn(i,n)
    {
        int d = 0;
        forn(j,m) if ( mat[r][j] != mat[i][j] ) ++d;
        res += min(d, m - d);
    }
    return res;
}

int countc(int c)
{
    int res = 0;
    forn(j,m)
    {
        int d = 0;
        forn(i,n) if ( mat[i][c] != mat[i][j] ) ++d;
        res += min(d, n - d);
    }
    return res;
}

int main()
{
    int k;
    while ( cin >> n >> m >> k )
    {
        forn(i,n) forn(j,m) scanf("%d", &mat[i][j]);
        int ans = inf;
        if ( n <= k && m <= k )
        {
            int a[10];
            forn(i,m) a[i] = mat[0][i];
            for(int mask = 0; mask < (1<<m); ++mask)
            {
                int cand = 0;
                forn(i,m)
                {
                    mat[0][i] = (mask >> i) & 1;
                    if ( mat[0][i] != a[i] ) ++cand;
                }
                cand += countr(0);
                ans = min(ans, cand);
            }
        }
        else if ( n > k )
        {
            forn(i,n) ans = min(ans, countr(i));
        }
        else // if ( m > k )
        {
            forn(i,m) ans = min(ans, countc(i));
        }
        cout << (ans <= k ? ans : -1) << endl;
    }
	
    return 0;
}
