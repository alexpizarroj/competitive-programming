#include <cstdio>
#include <cstring>
#include <cctype>

int main()
{
    typedef int Number;
    const int cstMax = 39;
    Number fib[45], calls[45];
    
    fib[0] = 0, fib[1] = 1;
    calls[0] = calls[1] = 0;
    for(int i = 2; i <= cstMax; ++i)
        fib[i] = fib[i-1] + fib[i-2],
        calls[i] = 2 + calls[i-1] + calls[i-2];
    
    int n, x;
    scanf("%d", &n);
    while ( n-- )
    {
        scanf("%d", &x);
        printf("fib(%d) = %d calls = %d\n", x, calls[x], fib[x]);
    }
    
    return 0;
}
