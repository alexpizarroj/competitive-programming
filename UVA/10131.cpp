#include <stdio.h>
#include <algorithm>
#define MAX 1000

using namespace std;

struct EL {
    int w; // Elephant weight
    int s; // Elephant IQ
    int pos; // Posición original del elefante en la lista original
    int nextIndex; // Siguiente nodo para lograr el peso de este índice
    int indexWeight; // Peso de este índice
};
static EL data[MAX];


bool cmp(EL a, EL b) { return a.w < b.w; }

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n = 0, i, j, w, s, length, nextIdx, nextIdxW, bestIdx, bestIdxW;

    // Lectura
    while ( scanf("%d %d", &w, &s) != EOF ) {
        data[n].w = w;
        data[n].s = s;
        data[n].pos = n+1;
        n++;
    }
    sort(data, data+n, cmp);
    // Resolucion (DP)
    bestIdx = -1; bestIdxW = 0;
    for(i = n-1; i != -1; i--) {
        length = 1; nextIdx = -1; nextIdxW = 0;
        for(j = i+1; j < n; j++) {
            if( data[j].s < data[i].s && data[j].w != data[i].w ) {
                if ( data[j].indexWeight > nextIdxW ) {
                    nextIdx = j;
                    nextIdxW = data[j].indexWeight;
                }
            }
        }
        length += (nextIdx != -1 ? nextIdxW : 0);
        data[i].nextIndex = nextIdx;
        data[i].indexWeight = length;
        // Determinar si es el nuevo BestIdx
        if(length > bestIdxW) {
            bestIdx = i;
            bestIdxW = length;
        }
    }
    // Salida
    printf("%d\n", bestIdxW);
    do {
        printf("%d\n", data[bestIdx].pos);
        bestIdx = data[bestIdx].nextIndex;
    } while ( bestIdx != -1 );
    // Mostrar datos
    /*
    for(i = 0; i != n; i++)
        printf("Int: %d, Pos: %d, NextInt: %d, Len: %d\n", i, data[i].pos, data[i].nextIndex, data[i].indexWeight);
    */

    return 0;
}
