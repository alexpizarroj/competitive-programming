#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ULL unsigned long long

using namespace std;


// fragmento de codigo extraido de Art of The Programming Contest.
// generador de Fibonacci, con proceso modular incluido para el ejercicio.
ULL fib(ULL n, int m) {
    ULL h, i, j, k, t;

    i = h = 1;
    j = k = 0;
    while (n > 0) {
        if (n%2 == 1) { // si n es impar
            t = (j*h)%m;
            j = (((i*h)%m + (j*k)%m)%m + t)%m;
            i = ((i*k)%m + t)%m;
        }

        t = (h*h)%m;
        h = (2*(k*h)%m)%m + t;
        k = (k*k)%m + t;

        n = (int) n/2;
    }

    return j%m;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, m;

    while ( scanf("%d %d", &n, &m) != EOF ) {
        m = pow(2, m);
        if (n == 0) {
            printf("0\n");
        } else if(n == 1 || n == 2) {
            printf("%d\n", 1%m);
        } else {
            printf("%llu\n", fib(n, m));
        }
    }

    return 0;
}

