#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t, T, n, m, tmp;

    scanf("%d", &T); T++;
    for (t = 1; t != T; t++) {
        // Resolucion
        scanf("%d", &n);
        scanf("%d", &m);
        n--;
        while ( n-- )  {
            scanf("%d", &tmp);
            if(tmp > m) m = tmp;
        }
        // Salida
        printf("Case %d: %d\n", t, m);
    }

    return 0;
}
