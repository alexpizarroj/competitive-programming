#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t, len, m, hop, i, k;
    char s[10002];

    scanf("%d", &t); getchar();
    while (t--) {
        // Entrada
        gets(s);
        len = strlen(s);
        hop = sqrt(len);
        if( hop*hop != len ) {
            printf("INVALID\n");
            continue;
        }
        // Resolucion y salida
        m = len-1;
        for(k = 0, i = 0; k != len; k++) {
            printf("%c", s[i]);
            s[i] = 0;
            i = (i+hop)%m;
            while ( s[i] == 0 ) i++;
        }
        printf("\n");
    }

    return 0;
}
