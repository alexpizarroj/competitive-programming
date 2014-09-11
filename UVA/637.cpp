#include <stdio.h>
#include <math.h>

using namespace std;


inline void print(int sheet, bool front, int page1, int page2) {
    if(page1==0 && page2==0) return;
    //
    printf("Sheet %d, ", sheet);
    printf( front ? "front: " : "back : " );
    if(page1==0) printf("Blank, "); else printf("%d, ", page1);
    if(page2==0) printf("Blank\n"); else printf("%d\n", page2);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, bestPages, pages, order[50][2];
    int i, j, k;
    bool shift;

    while ( true ) {
        // Emtrada
        scanf("%d", &n);
        if(!n) break;
        // Resolucion
        pages = ceil(n/4.0);
        bestPages = pages * 4;
        k = bestPages/2;
        shift = false;
        for(i = 0, j = 1; i != k; i++, j++, bestPages--) {
            order[i][shift] = (bestPages <= n ? bestPages : 0);
            order[i][!shift] = (j <= n ? j : 0);
            shift = !shift;
        }
        /* Test */ /*
        for(i = 0; i != k; i++)
            printf("%d-%d\n", order[i][0], order[i][1]);
        */
        // Salida
        printf("Printing order for %d pages:\n", n);
        i = 1; j = 0; k /= 2;
        while (k--) {
            print(i, true, order[j][0], order[j][1]);
            j++;
            print(i, false, order[j][0], order[j][1]);
            i++; j++;
        }
    }

    return 0;
}

