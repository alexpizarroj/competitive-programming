#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int n, m, a, b, r;

    while ( scanf("%d %d", &a, &b), (a || b) )
    {
        n = a, m = b;
        if ( n > m ) swap(n,m);

        if ( n < 1 )          r = 0;
        else if ( n == 1 )    r = m;
        else if ( n == 2 )    r = m / 4 * 4 + ( m%4 == 1 ? 2 : ( m%4 != 0 ? 4 : 0) );
        else                  r = ceil( double(n * m)/2 );

        printf("%d knights may be placed on a %d row %d column board.\n", r, a, b);
    }

    return 0;
}
