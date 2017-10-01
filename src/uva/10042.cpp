#include <stdio.h>
#include <math.h>

using namespace std;

static bool lastPrime;


inline int getsum(int n) {
    if(n < 10) return n;
    //
    int sum = 0;
    while ( n > 9) { sum += n%10; n /= 10; }
    return n+sum;
}

int getpsum(int n) {
    if(n == 1) { lastPrime = false; return 1; }
    int sum = 0, lim, i, m = n;
    //
    while (n%2 == 0) { n /= 2; sum += 2; }
    i = 3; lim = sqrt(n)+1;
    while (i <= lim) {
        if(n%i == 0) {
            sum += getsum(i);
            n /= i;
            lim = sqrt(n)+1;
        } else i += 2;
    }
    if(n != 1) sum += getsum(n);
    //
    lastPrime = (m == 2 || n == m);
    return sum;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int c, n, sum1, sum2;

    scanf("%d", &c);
    while (c--) {
        // Entrada
        scanf("%d", &n);
        // Resolucion
        while ( true ) {
            n++;
            sum1 = getpsum(n);
            if(lastPrime) continue;
            sum2 = getsum(n);
            if(sum1 == sum2) break;
        }
        // Salida
        printf("%d\n", n);
    }

    return 0;
}
