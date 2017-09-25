#include <stdio.h>
#include <algorithm>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t, T, v[3], i;

    scanf("%d", &T); T++;
    for (t = 1; t != T; t++) {
        // Resolucion
        for(i = 0; i != 3; i++) scanf("%d", &v[i]);
        sort(v, v+3);
        // Salida
        printf("Case %d: %d\n", t, v[1]);
    }

    return 0;
}
