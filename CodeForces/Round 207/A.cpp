#include <cstdio>

inline bool bet(int start, int mid, int end)
{
    return (start <= mid && mid <= end);
}

int main()
{
	int n, sum, left, right, x, y, k, vec[105];
    
    while ( ~scanf("%d", &n) )
    {
        sum = 0;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", vec+i);
            sum += vec[i];
        }
        scanf("%d %d", &x, &y);
        
        k = 2, left = vec[1], right = sum-left;
        while ( k <= n && !(bet(x, left, y) && bet(x, right, y) ) )
        {
            left += vec[k], right = sum - left;
            ++k;
        }
        printf("%d\n", k == n+1 ? 0 : k);
    }
    
    return 0;
}
