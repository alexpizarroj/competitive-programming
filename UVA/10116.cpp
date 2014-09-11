#include <stdio.h>
#define MAXSTEPS 120

using namespace std;

static char steps[MAXSTEPS+1][2]; // Lista de pasos dados (máximo 120), en formato fila-columna
static char map[11][11];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int r, c, i=1, j=1, nextStep, stepsCount, loopSteps;
    int row, column;
    bool checkNext;

    while ( true ) {
        // Entrada
        scanf("%d %d %d\n", &r, &c, &column);
        if( !(r+c+column) ) break;
        for(i = 1; i <= r; i++) {
            for(j = 1; j <= c; j++)
                scanf( "%c", &(map[i][j]) );
            getchar();
        }
        row = 1;
        nextStep = 1;
        stepsCount = 0;
        loopSteps = 0;
        checkNext = true;
        // Resolucion
        while ( row != 0 && row <= r && column != 0 && column <= c) {
            for(i = 1; i < nextStep; i++) {
                if( steps[i][0]==row && steps[i][1]==column ) {
                    loopSteps = stepsCount - i + 1;
                    stepsCount -= loopSteps;
                    checkNext = false;
                    break;
                }
            }
            if(!checkNext) break;
            stepsCount++;
            steps[nextStep][0] = row;
            steps[nextStep++][1] = column;
            switch ( map[row][column] ) {
                case 'N': row--; break;
                case 'S': row++; break;
                case 'E': column++; break;
                case 'W': column--; break;
            };
        }
        // Salida
        if(loopSteps)
            printf("%d step(s) before a loop of %d step(s)\n", stepsCount, loopSteps);
        else
            printf("%d step(s) to exit\n", stepsCount);
    }

    return 0;
}
