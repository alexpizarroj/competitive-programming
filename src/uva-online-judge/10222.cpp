#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 1001

using namespace std;

static char *m = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
static int mlen;


int getidx(char c) {
    for(int i = 0; i != mlen; i++)
        if( m[i] == c )
            return i;
    return -1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int i, j, len;
    char s[MAXLEN];
    mlen = strlen(m);

    while( gets(s) != NULL ) {
        // Normalizar cadena
        len = strlen(s);
        for(i = 0; i != len; i++)
            s[i] = tolower(s[i]);
        // Decodificar
        for(i = 0; i != len; i++) {
            if( s[i] != ' ') {
                j = getidx(s[i])-2;
                s[i] = m[j];
            }
        }
        // Salida
        printf("%s\n", s);
    }

    return 0;
}
