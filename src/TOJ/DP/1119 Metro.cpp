#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;
const double shortCost = sqrt(2) * 100;
int w, h; bitset<1002005> diag;

inline int id(int x, int y) { return y*(w+1) + x; }

int main()
{
    int k, cur;
    vector<double> dp[2];
    
    while ( ~scanf("%d %d", &w, &h) )
    {
        diag.reset();
        scanf("%d", &k);
        for(int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            diag[id(x-1,y-1)] = true;
        }
        cur = 0;
        for(int y = 0; y <= h; y++)
        {
            dp[cur].assign(w+1, 1e7);
            for(int x = 0; x <= w; x++)
            {
                if ( x + y == 0 )
                    dp[cur][x] = 0;
                if ( x > 0 )
                    dp[cur][x] = min(dp[cur][x], dp[cur][x-1] + 100);
                if ( y > 0 )
                    dp[cur][x] = min(dp[cur][x], dp[1-cur][x] + 100);
                if ( x > 0 && y > 0 && diag[id(x-1,y-1)] )
                    dp[cur][x] = min(dp[cur][x], dp[1-cur][x-1] + shortCost);
            }
            cur = 1-cur;
        }
        printf("%.0lf\n", dp[1-cur][w]);
    }
    
    return 0;
}