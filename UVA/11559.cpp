#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define BESTLEN 101
#define COSTNOTSET 2000001

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif


    int n, b, h, w, i, j;
    int cost, beds, bestcost;
    char s[BESTLEN];
    memset(s, 0, BESTLEN);

    while ( gets(s) ) {
        // Resolucion
        sscanf(s, "%d %d %d %d", &n, &b, &h, &w);
        bestcost = COSTNOTSET;
        i = h; while (i--) {
            scanf("%d\n", &cost);
            j = w; while (j--) {
                scanf("%d", &beds);
                if (beds > n) {
                    bestcost = min(bestcost, n*cost);
                    while (j--) scanf("%d", &beds);
                    break;
                }
            }
            getchar();
        }
        // Salida
        if( bestcost > b ) printf("stay home\n");
        else printf("%d\n", bestcost);
    }

    return 0;
}
