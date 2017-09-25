#include <cstring>
#include <cstdio>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
using namespace std;

short dp[1050000], mcost[1050000];
int main()
{
    int n, damage[21], mask[21], start;
    scanf("%d", &n);
    fup(i,0,n) scanf("%d", damage+i);
    start = (1<<n)-1;
    
    // Mask generation
    mask[0] = 7;
    fupi(i,1,n-3) mask[i] = mask[i-1]<<1;
    mask[n-2] = (mask[n-3]<<1)|1, mask[n-1] = (mask[n-2]<<1)|1;
    fupi(i,0,n-1) mask[i] = start&(~mask[i]);
    // Cost precalc
    fupi(i,1,start) fup(j,0,n) mcost[i] += bool(i&(1<<j)) * damage[j];
    // DP
    memset(dp, -1, sizeof dp), dp[0] = 0;
    fupi(cur,1,start) fup(i,0,n)
    {
        int next = cur & mask[i]; if ( cur == next ) continue;
        if ( dp[cur] == -1 || mcost[next] + dp[next] < dp[cur] )
        {
            dp[cur] = mcost[next] + dp[next]; 
        }
    }
    
    printf("%d\n", dp[start]);
	
    return 0;
}
