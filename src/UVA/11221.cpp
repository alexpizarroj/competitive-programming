#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <algorithm>
#define MAXLEN 10001

using namespace std;


static char s1[MAXLEN], s2[MAXLEN];

inline void strrev(char* str, const int len) {
    int i=0, j=len-1, k = len/2;
    while ( k-- ) swap( str[i++], str[j--] );
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t, T, i, j, len;
    bool magic;
    double root;

    scanf("%d\n", &T); T++;
    for(t = 1; t != T; t++) {
        // Entrada
        gets(s1);
        len = strlen(s1);
        for(i = 0, j = 0; i != len; i++)
            if( s1[i] >= 'a' && s1[i] <= 'z' )
                s2[j++] = s1[i];
        s2[j] = 0;
        // Resolucion
        len = j; magic = false;
        root = sqrt(len); i = sqrt(len);
        if ( root == i ) {
            memcpy(s1, s2, len+1);
            strrev(s2, len);
            magic = (strcmp(s1, s2) == 0);
        }
        // Salida
        printf("Case #%d:\n", t);
        if(magic)
            printf("%d\n", i);
        else
            printf("No magic :(\n");
    }


    return 0;
}
