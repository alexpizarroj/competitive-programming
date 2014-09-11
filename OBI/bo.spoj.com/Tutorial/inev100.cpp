#include <cstdio>

int main()
{
    int n;
    while ( scanf("%d", &n), n > 0 )
        printf("%d\n", 100 - n);
    return 0;
}
