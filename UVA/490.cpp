#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


static char sentences[100][101];
static char output[100][101];
static int sizes[100];


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int maxlen = 0, len, n = 0, i, j, l = 0;

    // Entrada
    while( gets(sentences[n]) != NULL ) {
        sizes[n] = strlen(sentences[n]);
        maxlen = max(maxlen, sizes[n]);
        n++;
    }
    // Proceso
    for(i = n-1; i != -1; i--) {
        len = sizes[i];
        for(j = 0; j != len; j++)
            output[j][l] = sentences[i][j];
        for(; j != maxlen; j++)
            output[j][l] = ' ';
        l++;
    }
    // Salida
    for(i = 0; i != maxlen; i++) {
        output[i][l] = 0;
        printf("%s\n", output[i]);
    }

    return 0;
}

