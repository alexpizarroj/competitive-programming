#include <cstdio>

int main()
{
    int h, m;
	while ( scanf("%d %d", &h, &m) != EOF )
		printf("%d %d\n", (360/12)*(h%12), (360/60)*m);
    return 0;
}
