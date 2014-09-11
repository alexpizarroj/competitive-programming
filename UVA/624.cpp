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
inline bool on(int mask, int pos) { return mask & (1<<pos); }


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, ntracks, tracks[20], i, j, top;
    int bestSum, bestMask, sum;
    bool first;

    while ( scanf("%d %d", &n, &ntracks) != EOF )
    {
        // Entradas e inicio
        FORX(i,0,ntracks) scanf("%d", &tracks[i]);
        top = 1 << ntracks;
        bestSum = bestMask = 0;

        // Resolucion
        FORX(i,0,top)
        {
            sum = 0;
            FORX(j,0,ntracks) if( on(i,j) ) sum += tracks[j];
            if( sum <= n && sum > bestSum )
            {
                bestSum = sum;
                bestMask = i;
                if( sum == n ) break;
            }
        }

        // Salida
        first = true;
        FORX(i,0,ntracks)
        {
            if( on(bestMask, i) )
            {
                if( first )
                {
                    printf("%d", tracks[i]);
                    first = false;
                }
                else
                {
                    printf(" %d", tracks[i]);
                }
            }
        }
        printf(" sum:%d\n", bestSum);
    }

    return 0;
}
