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

#define MAX_S 20000


int getMaxSum(int* v, int n, int* reti, int* retj)
{
    int i = 0, j = 0, k, sum = 0, maxSum, a, b;
    *reti = *retj = 0;

    FORX(k,0,n)
    {
        sum += v[k];
        if( k == 0 ) maxSum = sum-1;
        //
        if( sum > maxSum )
        {
            maxSum = sum;
            *reti = i;
            *retj = j = k;
        }
        else if ( sum == maxSum )
        {
            a = *retj+2 - *reti+1;
            b = k+2 - i+1;
            if(a < b)
            {
                *reti = i;
                *retj = j = k;
            }
        }
        if( sum < 0 )
        {
            sum = 0;
            if( k+1 < n ) i = j = k+1;
        }
    }

    return maxSum;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int b, r = 1, s, i, j;
    int v[MAX_S], sum;

    scanf("%d", &b);
    FORY(r,1,b)
    {
        // Entrada
        scanf("%d", &s); s--;
        FORX(i,0,s) scanf("%d", &v[i]);

        // Resolucion
        sum = getMaxSum(v, s, &i, &j);
        i++; j += 2;

        // Salida
        if( sum < 0 )
            printf("Route %d has no nice parts\n", r);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", r, i, j);
    }

    return 0;
}
