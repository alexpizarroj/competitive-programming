#include <cstdio>

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
    int n, cur = 1;

    scanf("%d", &n);
    while ( n-- )
    {
        printf("%d %d %d PUM\n", cur, cur+1, cur+2);
        cur += 4;
    }

    return 0;
}
