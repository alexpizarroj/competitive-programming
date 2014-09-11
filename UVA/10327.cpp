#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, *c, i, k, ans;
    int pos, swaps;

    while (scanf("%d\n", &n) != EOF) {
        // Datos
        c = new int[n];
        for(i=0;i<n;i++) {
            scanf("%d", &k);
            c[i] = k;
        }
        n--; ans = 0;
        // Bubble sort
        do {
            swaps = 0;
            for(i=0;i<n;i++) {
                if(c[i] > c[i+1]) {
                    swap(c[i], c[i+1]);
                    swaps++;
                }
            }
            ans += swaps;
        } while (swaps > 0);
        // Respuesta
        printf("Minimum exchange operations : %d\n", ans);
    }

    #ifndef ONLINE_JUDGE
        fclose(stdout);
    #endif
    return 0;
}
