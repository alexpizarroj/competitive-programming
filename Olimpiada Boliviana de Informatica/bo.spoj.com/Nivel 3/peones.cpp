#include <cstdio>

int main()
{
    int tc, vec[1000];
    scanf("%d", &tc);
    while ( tc-- )
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", vec+i);
        for(int i = n-1; i > 0; i--)
            vec[i-1] += (vec[i] / 2);
        printf("%d\n", vec[0]);
    }
    return 0;
}

