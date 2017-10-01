#include <iostream>
#include <cstdio>
using namespace std;

int N, E;
int f[505][505], bsum[505] = {0}, wsum[505] = {0};

inline int getCost(int i, int j)
{
    return (bsum[j]-bsum[i-1]) * (wsum[j]-wsum[i-1]);
}

int main()
{
    int horse;
    
    scanf("%d %d", &N, &E);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &horse);
        bsum[i] = bsum[i-1] + (horse == 1);
        wsum[i] = wsum[i-1] + (horse == 0);
    }
    
    for(int n = 1; n <= N-E+1; n++) f[1][n] = getCost(1,n);
    for(int e = 2; e <= E; e++)
    {
        for(int n = e; n <= N-E+e; n++)
        {
            f[e][n] = f[e-1][n-1] + getCost(n,n);
            for(int x = 2; x <= n-e+1; x++)
            {
                f[e][n] = min(f[e][n], f[e-1][n-x] + getCost(n-x+1,n));
            }
        }
    }
    printf("%d\n", f[E][N]);
	
    return 0;
}
