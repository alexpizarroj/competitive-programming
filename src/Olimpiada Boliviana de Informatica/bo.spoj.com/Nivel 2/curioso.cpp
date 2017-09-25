#include <cstdio>

int main()
{
    int f[10];
    f[0] = f[1] = 1;
    for(int i = 2; i < 10; i++)
        f[i] = i * f[i-1];
    int tc;
    scanf("%d", &tc);
    while ( tc-- )
    {
        int n, m;
        scanf("%d", &n);
        int sum = 0;
        m = n;
        while ( m > 0 )
        {
            int dig = m % 10;
            sum += f[dig];
            m /= 10;
        }
        puts(sum == n ? "Y" : "N");
    }
    return 0;
}
