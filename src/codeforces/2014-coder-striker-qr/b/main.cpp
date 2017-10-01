#include <iostream>
#include <cstdio>
#include <cstring>
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
using namespace std;

int main()
{
    int cell[105], core[105];
    int cellx[105], cmd[105][105], n, m, k;
    
    while ( cin >> n >> m >> k, cin )
    {
        fupi(i,1,n) fupi(j,1,m) cin >> cmd[j][i];
        memset(cell, 0, sizeof cell);
        memset(core, 0, sizeof core);
        fupi(i,1,m) 
        {
            memset(cellx, 0, sizeof cellx);
            fupi(j,1,n) if ( !core[j] ) ++cellx[cmd[i][j]];
            fupi(j,1,n) if ( !core[j] && cmd[i][j] > 0 )
            {
                int x = cmd[i][j];
                if ( cell[x] || cellx[x] > 1 ) core[j] = i;
                if ( cellx[x] > 1 ) cell[x] = true;
            }
        }
        fupi(i,1,n) printf("%d\n", core[i]);
    }
	
    return 0;
}
