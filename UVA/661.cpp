#include <stdio.h>
#include <algorithm>

using namespace std;


struct DEV { int cost; bool on; };

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int seq = 1, n, m, c, i, power, top;
    DEV v[20]; bool fused;

    while ( true ) {
        // Entrada
        scanf("%d %d %d", &n, &m, &c);
        if ( !(n+m+c) ) break;
        for(i = 0; i != n; i++) {
            scanf("%d", &(v[i].cost));
            v[i].on = false;
        }
        // Resolucion
        power = 0; top = 0; fused = false;
        while (m--) {
            scanf("%d", &i); i--;
            if (v[i].on)    { v[i].on = false;  power -= v[i].cost; }
            else            { v[i].on = true;   power += v[i].cost; }
            if(power > c)   {
                while (m--) scanf("%d", &i);
                fused = true;
                break;
            }
            top = max(top, power);
        }
        // Salida
        printf("Sequence %d\n", seq++);
        if(fused) {
            printf("Fuse was blown.\n");
        } else {
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", top);
        }
        printf("\n");
    }

    return 0;
}
