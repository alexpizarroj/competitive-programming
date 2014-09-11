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

#define MAX_N 100000
int v[MAX_N];


int getBest(int a, int b, int center) {
    int a1 = abs(a-center), b1 = abs(b-center);
    if ( a1 < b1 )			return a;
    else if ( a1 > b1 )		return b;
    else					return min(a,b);
}
int getBest(int a, int b) { return getBest(a,b,0); }

int getBestMatch(int n, int i, int j) {
    int mejor = v[i], mid;

    while ( i < j )
    {
        mid = (i+j)/2;
        mejor = getBest(mejor, v[mid], n);
        if ( n < v[mid] )		j = mid - 1;
        else if ( v[mid] < n )	i = mid + 1;
        else					return n;
    }
    mejor = getBest(mejor, v[i], n);

    return mejor;
}

int main() {
    //freopen("solucion.in", "r", stdin);
    //freopen("solucion.mine.out", "w", stdout);

    int t, n, negativos, positivos, inicioPositivos, mejor;
    int i, j, k;
    bool hayCero;

    scanf("%d", &t);
    while ( t-- )
    {
        // Entrada
        scanf("%d", &n);
        FORX(i,0,n) scanf("%d", &v[i]);

        // Dividir en lista de positivos y negativos
        i = negativos = positivos = 0;
        hayCero = false;
        while ( i < n && v[i] < 0 )
        {
            i++;
            negativos++;
        }
        positivos = n - negativos;
        if ( i < n && v[i] == 0 )
        {
            hayCero = true;
            i++;
            positivos--;
        }
        if ( i < n )	inicioPositivos = i;
        else			inicioPositivos = -1;

        // Comprobar casos especiales
        mejor = v[0] + v[1];
        if ( positivos > 0 )
			i = inicioPositivos - 1 - (hayCero ? 1 : 0);
        else
			i = n - 1;
        if ( negativos >= 2 )                   mejor = getBest(mejor, v[i-1] + v[i]);
        if ( positivos >= 2 )                   mejor = getBest(mejor, v[inicioPositivos] + v[inicioPositivos+1]);
        if ( negativos > 0 && hayCero )         mejor = getBest(mejor, v[i]);
        if ( positivos > 0 && hayCero )         mejor = getBest(mejor, v[inicioPositivos]);

        // Comprobar a aparear números de forma homogénea
        if( mejor != 0 && negativos > 0 && positivos > 0 )
        {
            int i1, j1, i2, j2;
            i1 = 0;
            j1 = inicioPositivos - 1 - (hayCero ? 1 : 0);
            i2 = inicioPositivos;
            j2 = n - 1;
            if(negativos > positivos)
            {
                swap(i1, i2);
                swap(j1, j2);
            }
            FORY(i,i1,j1)
            {
                k = v[i] * -1;
                j = getBestMatch(k, i2, j2);
                mejor = getBest(mejor, v[i] + j);
            }
        }

        // Salida
        printf("%d\n", mejor);
    }

    return 0;
}
