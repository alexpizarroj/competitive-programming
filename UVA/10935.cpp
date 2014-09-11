#include <stdio.h>
#include <algorithm>
#define NCARDS
using namespace std;


static int cards[NCARDS+1];

void moveCard(int top, int bot) {
    int tmp = cards[top];
    for(int i = top; i != bot; i--)
        cards[i] = cards[i-1];
    cards[bot] = tmp;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, i, j;

    while (true) {
        // Entrada
        scanf("%d", &n);
        if(n < 1) break;
        for(i = n, j = 1; i != 0; i--, j++)
            cards[i] = j;
        // Resolucion
        if(n != 1) {
            printf("Discarded cards: 1");
            n--; moveCard(n, 1);
        } else {
            printf("Discarded cards:");
        }
        while ( n != 1 ) {
            printf(", %d", cards[n]);
            n--; moveCard(n, 1);
        }
        printf("\nRemaining card: %d\n", cards[1]);
    }

    return 0;
}
