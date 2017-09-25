#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)

int main()
{
    int dp[105][105], n;
    char s[105];
  
    while ( scanf("%s", s), s[0] != 'e' )
    {
        n = strlen(s);
        fup(i,0,n) dp[i][i] = 0;
        fupi(k,2,n) fup(i,0,n-k+1)
        {
            int j = i+k-1;
            dp[i][j] = 0;
            if ( s[i] < s[j] && int(s[j]-s[i]) <= 2 )
            {
                dp[i][j] = 2 + ( i+2 <= j ? dp[i+1][j-1] : 0 );
            }
            fup(inter,i,j) dp[i][j] = max(dp[i][j], dp[i][inter]+dp[inter+1][j]);
        }
        printf("%d\n", dp[0][n-1]);
    }
	
    return 0;
}
