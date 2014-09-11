#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define PSC pair<char*, char>
#define MAXHEADERLEN 1000

using namespace std;

static PSC m[7][140];


char* tobin(int n) {
    int i = 6;
    char* ret = new char[8];

    ret[7] = 0;
    memset(ret, 48, 7);
    while (n > 1) {
        ret[i] = 48 + n%2;
        n /= 2;
        i--;
    }
    ret[i] = n+48;

    return ret;
}

void readstd(char* ret, int len) {
    char c;
    for(int i = 0; i != len; i++) {
        while ( true ) {
            c = getchar();
            if( c == '0' || c == '1') break;
        }
        ret[i] = c;
    }
}

char fromkey(const char* key, const int i) {
    int k = pow(2, i+1) - 1;
    for(int j = 0; j != k; j++) {
        if ( strcmp(key, m[i][j].first) == 0 ) return m[i][j].second;
    }
    return 0;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char *key, keyss[4], header[MAXHEADERLEN];
    int i, j, k, i2, j2, k2, keysize, keycount, n = 0;
    bool exitl;
    memset(header, 0, MAXHEADERLEN);
    memset(keyss, 0, 4);

    // Inicializacion
    for(i = 6; i != -1; i--) {
        k = pow(2, i+1) - 1; // total de claves
        k2 = 6-i-1; // limite inferior
        for(j = 0; j != k; j++) {
            if(i == 6) {
                m[i][j].first = tobin(n); n++;
            } else {
                key = new char[i+2]; key[i+1] = 0;
                for(i2 = 6, j2 = i; k2 != i2; i2--, j2--) key[j2] = m[6][j].first[i2];
                m[i][j].first = key;
            }
        }
    }

    // Proceso
    while ( gets(header) ) {
        // Mapeo
        keycount = strlen(header); i2 = 0;
        for(i = 0; i != 7; i++) {
            k = pow(2, i+1) - 1;
            for(j = 0; j != k; j++) {
                if(i2==keycount) break;
                m[i][j].second = header[i2];
                i2++;
            }
            if(i2==keycount) break;
        }
        while ( true ) {
            // Tamanio actual de clave
            readstd(keyss, 3);
            keysize = (keyss[0]-48)*4 + (keyss[1]-48)*2 + keyss[2]-48;
            if (keysize == 0) break;
            key = new char[keysize+1]; key[keysize] = 0;
            // Lectura de codigos
            while ( true ) {
                readstd(key, keysize); exitl = true;
                for(i = 0; i != keysize; i++) exitl &= key[i] == '1';
                if(exitl) break;
                printf( "%c", fromkey(key, keysize-1) );
            }
        }
        printf("\n");
        memset(header, 0, MAXHEADERLEN); getchar();
    }

    return 0;
}
