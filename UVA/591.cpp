#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int ans, n, i, t, caseNo = 1, v[50];

    while (true) {
        // Entrada
        scanf("%d", &n);
        if(!n) break;
        t = 0;
        for(i = 0; i != n; i++) {
            scanf("%d", &v[i]);
            t += v[i];
        }
        t /= n;
        // Resolucion
        ans = 0;
        for(i = 0; i != n; i++) if( v[i] > t ) ans += v[i]-t;
        // Salida
        printf("Set #%d\n", caseNo++);
        printf("The minimum number of moves is %d.\n\n", ans);
    }

    return 0;
}
