#include <cstdio>

int main()
{
    int best, pos = 1;
    
    scanf("%d", &best);
    for(int i = 2; i <= 100; ++i)
    {
        int value;
        scanf("%d", &value);
        if ( value > best )
            best = value, pos = i;
    }
    printf("%d\n%d\n", best, pos);
    
    return 0;
}