#include <stdio.h>
#include <memory.h>
#define MAXINT 32768
#define MAXINTSQRT 181

static bool prime[MAXINT+1];

using namespace std;


void init() {
    int i, j;

    memset(prime, true, MAXINT+1);
    prime[0] = false; prime[1] = false;
    for(i = 4; i <= MAXINT; i += 2) prime[i] = false;
    for(i = 3; i <= MAXINTSQRT; i += 2) {
        if( prime[i] ) {
            for(j = i*i; j <= MAXINT; j += i)
                prime[j] = false;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, i, j, count;

    init();
    while ( true ) {
        // Entrada
        scanf("%d", &n);
        if(!n) break;
        // Resolucion
        count = 0;
        for(i = 2, j = n-2; i <= j; i++, j--)
            if( prime[i] && prime[j] ) count++;
        // Salida
        printf("%d\n", count);
    }

    return 0;
}
