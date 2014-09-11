#include <cstdio>
#include <cstdlib>
bool dp[1005][1005];
int choice[1005][1005];

int main()
{
    char s1[1005], s2[1005];
    int sum1[1005], sum2[1005], n, n0, n1;
    
    while ( ~scanf("%d", &n) )
    {
        scanf("%s %s", s1, s2);
        sum1[0] = sum2[0] = 0;
        for(int i=0; i<n; ++i) 
        {
            sum1[i+1] = sum1[i] + (s1[i]-'0');
            sum2[i+1] = sum2[i] + (s2[i]-'0');
        }
        
        dp[n][n] = 1;
        for(int i=0; i<=n; ++i) dp[i][n+1] = dp[n+1][i] = 0;
        for(int i = n; i >= 0; --i) for(int j = n; j >= 0; --j)
        {
            if ( i == j && j == n ) continue;
            
            n1 = sum1[i]+sum2[j], n0 = i+j-n1;
            choice[i][j] = 0, dp[i][j] = 0;
            if ( abs(n0-n1) <= 1 )
            {
                if ( dp[i+1][j] )      choice[i][j] = 1, dp[i][j] = 1;
                else if ( dp[i][j+1] ) choice[i][j] = 2, dp[i][j] = 1;
            }
        }
        
        if ( dp[0][0] )
        {
            int x = 0, y = 0;
            while ( x != n || y != n )
            {
                printf("%d", choice[x][y]);
                if ( choice[x][y] == 1 ) ++x; else ++y;
            }
            puts("");
        } else puts("Impossible");
    }
	
    return 0;
}
