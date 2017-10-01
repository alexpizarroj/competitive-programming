#include <cstring>
#include <cstdio>
const int MAX = 1e6+10;
int dp[MAX];

int seqlen(long long n)
{
    int ans;

    if ( n < MAX )
    {
        ans = dp[n];
        if ( ans == -1 )
        {
            if ( n&1 )  ans = 1 + seqlen(3*n+1);
            else        ans = 1 + seqlen(n/2);
            dp[n] = ans;
        }
    }
    else
    {
        ans = 0;
        while ( n >= MAX )
        {
            if ( n&1 )  n = 3*n+1;
            else        n /= 2;
            ++ans;
        }
        ans += seqlen(n);
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

    int l, h, best, cand, ans;

	memset(dp, -1, sizeof dp);
	dp[0] = dp[1] = 0;

	while ( scanf("%d %d", &l, &h), l || h )
	{
	    if ( l > h ) l ^= h, h ^= l, l ^= h; // swap
	    ans = l, best = ( l == 1 ? 3 : seqlen(l) );
	    for(int i = l+1; i <= h; ++i)
	    {
	        cand = seqlen(i);
	        if ( cand > best ) ans = i, best = cand;
	    }
	    printf("Between %d and %d, %d generates the longest sequence of %d values.\n", l, h, ans, best);
	}

    return 0;
}
