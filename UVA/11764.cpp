#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int T, t;
    int n, a, b, low, high;

    scanf("%d", &T); T++;
    for (t = 1; t != T; t++) {
        // Resolucion
        scanf("%d", &n);
        low = 0; high = 0;
        scanf("%d", &a);
        if(n != 1) {
            n--; while (n--) {
                scanf("%d", &b);
                if(a > b) low++; else if (a < b) high++;
                a = b;
            }
        }
        // Salida
        printf("Case %d: %d %d\n", t, high, low);
    }

    return 0;
}
