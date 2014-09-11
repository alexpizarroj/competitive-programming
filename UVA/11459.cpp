#include <stdio.h>
#include <memory.h>
#define TABLE 100
#define MAX 1000000

using namespace std;


static char port[TABLE+1], player[MAX+1];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int T, portCnt, currentPlayer, players, rolls;
    int i, j;

    scanf("%d", &T);
    while (T--) {
        // Entrada
        scanf("%d %d %d", &players, &portCnt, &rolls);
        memset(port, 0, TABLE+1);
        while (portCnt--) {
            scanf("%d %d", &i, &j);
            port[i] = j;
        }
        // Resolucion
        currentPlayer = 1;
        memset(player, 1, players+1);
        while(rolls--) {
            scanf("%d", &i);
            player[currentPlayer] += i;
            if(player[currentPlayer] > 100) player[currentPlayer] = 100;
            if( port[(int)player[currentPlayer]]!=0 )
                player[currentPlayer] = (int)port[(int)player[currentPlayer]];
            //
            if(player[currentPlayer] == 100) {
                while(rolls--) scanf("%*d");
                break;
            }
            //
            currentPlayer++;
            if(currentPlayer > players) currentPlayer = 1;
        }
        // Salida
        for(i = 1, players++; i != players; i++)
            printf("Position of player %d is %d.\n", i, player[i]);
    }

    return 0;
}
