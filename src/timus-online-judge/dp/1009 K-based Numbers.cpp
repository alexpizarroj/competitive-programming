#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
typedef long long ll;

#define MAX 20
ll dp[MAX][MAX];
// function declaration
ll f(ll,ll);
ll r(ll,ll);

ll f(ll n, ll k)
{
    if ( dp[n][k] == -1 )
    {
        dp[n][k] = k*f(n-1,k) + r(n-2,k);
    }
    return dp[n][k];
}

ll r(ll n, ll k) { return (k-1) * ( pow(k,n-1) - f(n-1,k) ); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, k;

    memset(dp, -1, sizeof dp);
    fup(i,0,MAX) dp[0][i] = dp[1][i] = 0, dp[2][i] = 1;
	while ( scanf("%d %d", &n, &k) != EOF )
	{
	    printf("%lld\n", r(n,k));
	}

    return 0;
}
