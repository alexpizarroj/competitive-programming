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

int v[50000];
int main() {
    //freopen("data.in", "r", stdin);

    int n, q, i, h;
    int *p, idx;

    while ( scanf("%d", &n) != EOF )
    {
        for(i=0; i<n; i++) scanf("%d", v+i);

        scanf("%d", &q);
        for(i=0; i<q; i++)
        {
            scanf("%d", &h);
            p = lower_bound(v, v+n, h);
            idx = p - v;

            if( idx == n )
                // El valor no existe y llegamos al final de la lista sin encontrar un mayor
                printf("%d X\n", v[n-1]);
            else if ( v[idx] == h )
            {
                // Estamos parados en el valor exacto
                if( idx > 0 )   printf("%d ", v[idx-1]);
                else            printf("X ");
                while( v[idx] == h && idx < n ) idx++;
                if( idx < n ) printf("%d\n", v[idx]);
                else            printf("X\n");
            } else {
                // El valor no existe, estamos parados en el valor inmediatamente mayor a ese
                if( idx > 0 )   printf("%d ", v[idx-1]);
                else            printf("X ");
                printf("%d\n", v[idx]);
            }
        }
    }

    return 0;
}
