#include <cstdio>

int main()
{
	//freopen("input.txt", "r", stdin);

	int n, cnt;
	while ( scanf("%d", &n) != EOF )
	{
        for(cnt = 1, n >>= 1; n > 0; n >>= 1, cnt++);
        printf("%d\n", cnt);
	}
    return 0;
}
