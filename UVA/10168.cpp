#include <stdio.h>
#include <memory.h>
#define MAXINT 10000000
#define MAXINTSQRT 3162

static bool primo[MAXINT+1];
using namespace std;


void initCriba() {
    int i, j;

    memset(primo, 1, MAXINT);
    primo[0] = 0; primo[1] = 0;

    for(i = 4; i <= MAXINT; i += 2) primo[i] = 0;
    for(i = 3; i <= MAXINTSQRT; i += 2) {
        if(primo[i])
            for(j = i*i; j <= MAXINT; j += i)
                primo[j] = 0;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, i;
    bool even;

    initCriba();
    while ( scanf("%d", &n) != EOF ) {
        // Prueba
        if(n < 8) {
            printf("Impossible.\n");
            continue;
        }
        // Forzar a par
        even = (n%2==0);
        if(even) printf("2 2 "); else printf("2 3 ");
        n -= 4+(even ? 0 : 1);
        // Buscar suma de dos primos
        n -= 2;
        for(i = 2; n >= 2; i++, n--) {
            if(primo[i] && primo[n]) {
                printf("%d %d", i, n);
                break;
            }
        }
        printf("\n");
    }

    return 0;
}
