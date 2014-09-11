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

int N, K;
i64 pwr[510*510], dp[510][510];

i64 f(int n, int k)
{
    if ( dp[n][k] == -1 )
    {
        i64 &ans = dp[n][k];
        if ( k == 0 ) ans = 1;
        else {
            ans = 0;
            for(int c = 1; n+c <= N; ++c)
            {
                ans += f(n+c, k-1) * ((pwr[c]-1) * pwr[(N-n-c)*c] % inf) % inf;
            }
            ans %= inf;
        }
    }
    return dp[n][k];
}

int main()
{
    pwr[0] = 1;
    for(int i = 1; i < 510*510; ++i) pwr[i] = pwr[i-1] * 2 % inf;
    while ( cin >> N >> K )
    {
        memset(dp, -1, sizeof dp);
        cout << f(0, K) << endl;
    }
    return 0;
}
