#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define F 100
#define F2 F+2
#define C 100
#define C2 C+2
//#define JUDGE

using namespace std;

static bool m[F2][C2]; // 1-20, 1-100

void showM(int cols) {
    int i, j;
    for(i = 0; i <= cols+1; i++) {
        for(j = 0; j <= 101; j++) {
            printf(" %d", m[i][j]);
        }
        printf("\n");
    }
    printf("-------\n");
}

int main() {
    #ifndef JUDGE
    freopen("tetris.in", "r", stdin);
    freopen("tetris.mine.out", "w", stdout);
    #endif

    int casos, cols, i, j, k, maximun, start, ans;

    scanf("%d", &casos);
    while (casos--) {
        // Lectura
        scanf("%d", &cols);
        memset(m, 0, sizeof(bool)*22*102);
        maximun = 0; start = 1;

        // Paso a matriz
        for(i = 1; i <= cols; i++) {
            scanf("%d", &k);
            maximun = max(maximun, k);
            for(j = 1; j <= k; j++)
                m[i][j] = true;
        }

        // Encerar filas llenar de unos
        for(j = 1; j <= maximun; j++) {
            k = 0;
            for (i = 1; i <= cols; i++) k += m[i][j];
            if( cols == k ) {
                for (i = 1; i <= cols; i++) m[i][j] = 0;
                start++;
            } else {
                break;
            }
        }
        //printf("Start: %d Top: %d\n", start, maximun); showM(cols);

        // Resolucion
        ans = 0;
        for(j = start; j <= maximun; j++) {
            for(i = 1; i <= cols; i++) {
                if ( m[i][j]==1 ) {
                    ans += 6 - m[i+1][j] - m[i-1][j] - m[i][j+1] - m[i][j-1];
                }
            }
        }
        printf("%d\n", ans);
    }

    #ifndef JUDGE
    fclose(stdout);
    #endif
    return 0;
}
