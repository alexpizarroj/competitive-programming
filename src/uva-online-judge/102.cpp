#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define UINT unsigned int
#define maxstrlen 100

using namespace std;

struct bin { UINT b, g, c; } v[3];

UINT getmoves(char order[3]) {
    int binNo, i, j, cfg[3]; UINT moves = 0;

    for(i = 0; i != 3; i++) {
        switch(order[i]) {
            case 'B': cfg[i] = 0; break;
            case 'G': cfg[i] = 1; break;
            case 'C': cfg[i] = 2; break;
        }
    }
    for(i = 0; i != 3; i++) {
        binNo = cfg[i];
        for(j = 0; j != 3; j++) {
            if (j==i) continue;
            switch(binNo) {
                case 0: moves += v[j].b; break;
                case 1: moves += v[j].g; break;
                case 2: moves += v[j].c; break;
            };
        }
    }

    return moves;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    UINT data[9], moves, bestMoves;
    char input[maxstrlen], binOrder[3], bestOrder[3], outOrder[4];

    memset(input, 0, maxstrlen); outOrder[3] = 0;
    while (gets(input)) {
        // Entrada
        sscanf(input, "%u %u %u %u %u %u %u %u %u",
               &data[0], &data[1], &data[2], &data[3], &data[4], &data[5], &data[6], &data[7], &data[8]);
        v[0].b = data[0]; v[0].g = data[1]; v[0].c = data[2];
        v[1].b = data[3]; v[1].g = data[4]; v[1].c = data[5];
        v[2].b = data[6]; v[2].g = data[7]; v[2].c = data[8];
        // Resolucion
        binOrder[0] = 'B'; binOrder[1] = 'C'; binOrder[2] = 'G';
        bestMoves = getmoves(binOrder);
        memcpy(bestOrder, binOrder, 3);
        while (next_permutation(binOrder, binOrder+3)) {
            moves = getmoves(binOrder);
            if (moves < bestMoves) {
                bestMoves = moves;
                memcpy(bestOrder, binOrder, 3);
            }
        }
        memcpy(outOrder, bestOrder, 3);
        // Salida
        printf("%s %u\n", outOrder, bestMoves);
    }

    return 0;
}
