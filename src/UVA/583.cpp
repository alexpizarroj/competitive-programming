#include <stdio.h>
#include <math.h>

using namespace std;

static bool first;


inline void write(int n) {
    printf( (first ? "%d" : " x %d") , n);
    first = false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int g, i, lim;

    while (true) {
        // Entrada
        scanf("%d", &g);
        if(!g) break;
        // Salida
        first = true;
        printf("%d = ", g);
        if(g < 0)  {
            printf("-1 x ");
            g*=-1;
        }
        //
        while (g%2==0) {
            write(2);
            g /= 2;
        }
        i= 3;
        lim = sqrt(g)+1;
        while (i <= lim) {
            if(g%i==0) {
                write(i);
                g /= i;
                lim = sqrt(g)+2;
            } else {
                i += 2;
            }
        }
        if(g > 1) write(g);
        //
        printf("\n");
    }

    return 0;
}
