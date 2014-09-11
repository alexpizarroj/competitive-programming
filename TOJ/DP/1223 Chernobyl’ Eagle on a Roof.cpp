#include <cstdio>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
int dp[1005][1005]; // dp(d, e);

int main()
{
    int n, k, x;
    
    fupi(i,0,1000) dp[i][0] = dp[0][i] = 0;
    fupi(d,1,1000) fupi(e,1,1000) dp[d][e] = dp[d-1][e-1] + dp[d-1][e] + 1;
    while ( scanf("%d %d", &n, &k), n || k )
    {
        for(x = 1; dp[x][n] < k; ++x);
        printf("%d\n", x);
    }
	
    return 0;
}
