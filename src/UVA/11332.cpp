#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, sum;


    while ( scanf("%d", &n) != EOF ) {
        if (!n) break;
        // Resolucion
        while (n > 9) {
            sum = 0;
            while (n > 9) {  sum += n%10;  n /= 10;  }
            n += sum;
        }
        // Salida
        printf("%d\n", n);
    }

    return 0;
}
