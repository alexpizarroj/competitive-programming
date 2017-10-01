#include <cstdio>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)

bool dp[35][1000005];
int powerMod[3][31], N; // powerMod(d,n) = ( d * 10^(n-1) ) % N

inline int nextrem(int d, int n, int r)
{ return ( r - powerMod[d][n] + ( powerMod[d][n] > r ? N : 0 ) ); }

int main()
{   
    // DP
    scanf("%d", &N);
    fupi(i,1,2)
    {
        powerMod[i][1] = i%N;
        fupi(n,2,30) powerMod[i][n] = (powerMod[i][n-1]*10)%N;
    }
    fup(r,0,N) dp[1][r] = 0;
    dp[1][1%N] = dp[1][2%N] = 1;
    fupi(n,2,30) fup(r,0,N)
    {
        dp[n][r] = dp[n-1][nextrem(1,n,r)] || dp[n-1][nextrem(2,n,r)];
    }
    
    // Output
    int anslen = 0;
    fupi(n,1,30) if ( dp[n][0] )  { anslen = n; break; }
    if ( anslen > 0 )
    {
        int r = ( anslen == 1 ? N : 0);
        while ( anslen > 1 )
        {
            if ( dp[anslen-1][nextrem(1,anslen,r)] ) 
            {
                putchar('1');
                r = nextrem(1,anslen,r);
            }
            else
            {
                putchar('2');
                r = nextrem(2,anslen,r);
            }
            --anslen;
        }
        putchar(r+'0');
        puts("");
    }
    else puts("Impossible");
    
    return 0;
}