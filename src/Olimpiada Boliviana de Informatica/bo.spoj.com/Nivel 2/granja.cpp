#include <cstdio>
 
int main()
{
    long long x, y;
    while ( scanf("%lld %lld", &y, &x), x != 0 || y != 0 )
    {
        if ( x%2 == 0 && 2*y <= x && x <= 4*y )
            printf("%lld %lld\n", (4*y-x)/2, (x-2*y)/2);
        else
            puts("-1");
    }
    return 0;
}