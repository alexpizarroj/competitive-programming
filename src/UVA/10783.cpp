#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int N, n, a, b, i, ans;

    scanf("%d", &N); N++;
    for(n = 1; n != N; n++) {
        // Entrada
        scanf("%d %d", &a, &b);
        // Resolucion
        ans = 0;
        if (a%2 == 0) a++; if (b%2 == 2) b--;
        for(i = a; i <= b; i+=2) ans += i;
        // Salida
        printf("Case %d: %d\n", n, ans);
    }

    return 0;
}
