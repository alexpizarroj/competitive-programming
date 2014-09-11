#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

    int tc, n, k, last, caseNo = 0;

    scanf("%d", &tc);

    while ( tc-- )
    {
        scanf("%d %d", &n, &k);
		last = 0;
        for(int i = 2; i <= n; ++i) last = ( last+k )%i;
        printf("Case %d: %d\n", ++caseNo, last+1 );
    }

    return 0;
}
