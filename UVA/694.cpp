#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    long long int b;
    int a, l, steps, caseNo = 1;

    while ( true ) {
        // Entrada
        scanf("%d %d", &a, &l);
        if(a < 0 && l < 0) break;
        // Resolucion
        steps = 0; b = a;
        while ( b <= l ) {
            steps++;
            if(b == 1) break;
            else if(b%2 == 0) b /= 2;
            else b = (3*b)+1;
        }
        // Salida
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n", caseNo++, a, l, steps);
    }

    return 0;
}
