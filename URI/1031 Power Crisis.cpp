#include <cstdio>

int getLast(int n, int m)
{
    int last = 0;
    for(int sz = 2; sz <= n; ++sz)
        last = 1 + ( m-1 + last )%(sz-1);
    return last+1;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	while ( scanf("%d", &n), n > 0 )
	{
        m = 1;
        while ( getLast(n, m) != 13 ) ++m;
        printf("%d\n", m);
	}
    return 0;
}
