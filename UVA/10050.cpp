#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <list>
#include <sstream>
#include <string>
#include <cstring>

#include <memory.h>
#include <algorithm>
#include <cmath>

#define FORX(i,start,end) for(i=start;i<end;i++)
#define FORY(i,start,end) for(i=start;i<=end;i++)

using namespace std;

#define MAX_N 3650
#define MAX_P 100


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int ntest, n, p, h[MAX_P], lostDays;
    bool dayIsLost[MAX_N+1];
    int i, j;

    cin >> ntest;
    while ( ntest-- )
    {
        // Entrada
        cin >> n >> p;
        FORX(i,0,p) cin >> h[i];

        // Resolucion
        memset(dayIsLost, 0, sizeof dayIsLost);
        lostDays = 0;
        FORY(i,1,n)
        {
            if( i%7==6 || i%7==0 ) continue;
            FORX(j,0,p)
            {
                if( i%h[j] == 0 )
                {
                    dayIsLost[i] = 1;
                    break;
                }
            }
        }
        FORY(i,1,n)
            if( dayIsLost[i] ) lostDays++;

        // Salida
        cout << lostDays << endl;
    }

    return 0;
}
