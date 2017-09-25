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
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define MSB(n) ( n <= 0 ? 0 : int(floor(log(n)/log(2))) )
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;

const int INF = int(1E9+7);
const double EPS = 1e-6;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> ii;
typedef vector<int> vi;

int dp[5010][5010];
inline int g(int a, int b, int x) { return dp[b+1][x] - dp[a][x]; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

    vi v;
    int n, x, baseCost, candidate;
    int best, nPairs;

    fup(i,0,n) dp[0][i] = 0;

    while ( cin >> n )
    {
        v.clear();
        fup(i,0,n) cin >> x, v.PB(x);

        fupi(i,1,n) fup(j,0,n) dp[i][j] = dp[i-1][j] + (v[i-1] > j);
        baseCost = 0; fup(i,0,n) baseCost += dp[i][v[i]];

        best = nPairs = 0;
        fup(i,0,n) fup(j,i+1,n) if ( v[i] > v[j] )
        {
            candidate = 2 * ( g(i, j, v[i]) - g(i, j, v[j]) ) + 1;
            if ( candidate < best )
                best = candidate, nPairs = 1;
            else if ( candidate == best )
                ++nPairs;
        }

        cout << baseCost+best << " " << nPairs << endl;
    }

    return 0;
}
