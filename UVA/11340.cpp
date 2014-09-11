#include <stdio.h>
#include <memory.h>
#include <string.h>
#define BESTLEN 10001
#define UCHAR unsigned char

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, k, i, len, m[256];
    unsigned long long r;
    UCHAR c, s[BESTLEN];
    memset(s, 0, BESTLEN);

    scanf("%d", &n); getchar();
    while (n--) {
        // Entrada
        memset(m, 0, 256*sizeof(int));
        scanf("%d", &k); getchar();
        while (k--) {
            scanf("%c %d", &c, &i); getchar();
            m[(int)c] = i;
        }
        // Resolucion
        r = 0; scanf("%d", &k); getchar();
        while (k--) {
            gets((char*)s);
            len = strlen((char*)s);
            for(i = 0; i != len; i++) r += m[(int)s[i]];
        }
        // Salida
        k = (int)(r%100); r = (r-k)/100;
        printf("%llu.%.2d$\n", r, k);
    }

    return 0;
}
