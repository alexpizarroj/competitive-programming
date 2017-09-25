#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char sx[1000001];


int main() {
    //freopen("venganza.mine.in", "r", stdin);
    freopen("venganza.in", "r", stdin); freopen("venganza.mine.out", "w", stdout);

    char *x, sk[21];
    int casos, k, klen, xlen;
    int i, j;

    scanf("%d", &casos); getchar();
    while ( casos--) {

        // Entrada
        scanf("%s %d", sx, &k); getchar();

        // Pasar K a binario
        i = 0;
        do {
            sk[i++] = k%2 + '0';
            k /= 2;
        } while (k != 0);
        sk[i] = 0;
        klen = i;

        // Invertir k en binario para que quede correctamente
        k = i/2;
        for(j = i-1, i = 0; i != k; i++, j--) swap(sk[i], sk[j]);

        // Ignorar ceros no signifiscativos
        i = 0;
        while ( sx[i]=='0' ) i++;
        x = sx+i;
        xlen = strlen(x);

        // Comprobar si se va a poder llegar al valor pedido
        if( klen > xlen || (sk[klen-1] == '1' && x[klen-1] == '0') )
            printf("No\n");
        else {
            sk[--klen] = 0;
            x[klen] = 0;
            if( strcmp(sk, x) == 0 )
                printf("Si\n");
            else
                printf("No\n");
        }

    }

    return 0;
}
