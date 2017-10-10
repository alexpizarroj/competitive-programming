#include <stdio.h>
#include <memory.h>
#define MAXINT 1000000
#define MAXINTSQRT 1000

using namespace std;

static bool valid[MAXINT+1];


void init() {
    int i, j;

    memset(valid, 1, MAXINT+1);
    //valid[0] = false; valid[1] = false;
    //for(i = 2; i <= MAXINT; i += 2) valid[i] = false;
    for(i = 3; i <= MAXINTSQRT; i += 2)
        if ( valid[i] ) {
            for(j = i*i; j <= MAXINT; j += i)
                valid[j] = false;
        }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, i, j, k;
    bool found;

    init();
    while ( true ) {
        // Entrada
        scanf("%d", &n);
        if(!n) break;
        // Resolucion
        k = ( n - (n%2==0 ? 1 : 0) - 2 );
        found = false;
        for (i = 3, j = n-3; i <= k; i += 2, j -= 2) {
            if( valid[i] && valid[j] ) {
                printf("%d = %d + %d\n", n, i, j);
                found = true;
                break;
            }
        }
        if(!found) printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}
