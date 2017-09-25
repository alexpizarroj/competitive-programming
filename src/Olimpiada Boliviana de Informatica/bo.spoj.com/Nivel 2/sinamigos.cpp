#include <cstdio>
#include <cmath>

int f(int n)
{
    int sum = 0, lim = (int)floor(sqrt(n));
    for(int i = 1; i <= lim; i++)
        if ( n%i == 0 )
            sum += i + (n/i);
    return sum - n - (lim*lim == n ? lim : 0);
}

int main()
{
    int n;
    while ( scanf("%d", &n) != EOF )
    {
        int fr = f(n);
        printf("%d\n", f(fr) == n ? fr : -1);
    }
    return 0;
}
