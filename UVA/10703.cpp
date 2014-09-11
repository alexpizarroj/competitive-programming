// IO
#include <iostream>
#include <cstdio>
// STL
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;
// STRINGS
#include <string>
#include <cstring>
// OTROS
#include <cstdlib>
#include <memory.h>
#include <cmath>
// MACROS
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()

bool grid[501][501];

int main() {
    //freopen("data.in", "r", stdin);

    int w,h,n,x1,y1,x2,y2,i,j,k;

    while( true )
    {
        scanf("%d %d %d", &w, &h, &n);
        if( w == h && h == n && n == 0 ) break;

        memset(grid, true, sizeof grid);
        for(k=0; k<n; k++)
        {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if( x1 > x2 ) swap(x1,x2);
            if( y1 > y2 ) swap(y1,y2);
            for(i=x1; i<=x2; i++)
                for(j=y1; j<=y2; j++)
                    grid[i][j] = false;
        }

        k=0;
        for(i=1; i<=w; i++)
            for(j=1; j<=h; j++)
                if( grid[i][j] ) k++;

        if( k == 0 )
            puts("There is no empty spots.");
        else if ( k == 1 )
            puts("There is one empty spot.");
        else
            printf("There are %d empty spots.\n", k);
    }

    return 0;
}
