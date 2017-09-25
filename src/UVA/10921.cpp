#include <stdio.h>
#include <string.h>
#include <memory.h>

using namespace std;


static char m[128];


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int i, j;
    char s[31], k = 'A';
    memset(s, 0, 31);

    // Rellenar mapa
    m['-'] = '-'; m['0'] = '0'; m['1'] = '1';
    for(i = 2, k = 65; i != 10; i++) {
        j = ( (i == 7 || i == 9) ? 4 : 3 );
        while (j--) {
            m[k] = i+'0';
            k++;
        }
    }
    // Resolucion
    while ( gets(s) ) {
        k = strlen(s);
        for(i = 0; i != k; i++)
            printf("%c", m[s[i]] );
        printf("\n");
    }

    return 0;
}
