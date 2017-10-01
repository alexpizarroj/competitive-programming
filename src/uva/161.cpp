#include <stdio.h>
#include <algorithm>
#include <memory.h>
#define TIME_NOT_SET 99
#define MAX_TIME 18000

using namespace std;


static int times[100];
static bool on[MAX_TIME+1];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, i, j, k, time;
    bool found;

    while ( true ) {
        // Entrada
        n = 0; time = TIME_NOT_SET;
        while (true) {
            scanf("%d", &i);
            if(!i) break;
            times[n++] = i;
            time = min(time, i);
        }
        if(!n) break;
        memset(on, true, MAX_TIME+1);
        time -= 4;
        // Resolucion¡
        for(i = 0; i != n; i++)
            for(j = times[i]; j <= MAX_TIME; j += times[i]*2)
                memset(on+j-5, false, times[i]+5);
        found = false;
        for(i = time; i <= MAX_TIME; i++) {
            if( on[i] ) {
                time = i;
                found = true;
                break;
            }
        }
        /*
        // Muestra de 60 segundos
        for(i = 0, j = 0; i != 60; i++, j++) {
            if(j==5) { j = 0; printf("-"); }
            printf("%d", on[i]);
        }
        printf("\n");
        */
        // Salida
        if( found ) {
            printf("%02d:%02d:%02d\n", time/3600, (time%3600)/60, time%60);
        }
        else
            printf("Signals fail to synchronise in 5 hours\n");
    }

    return 0;
}
