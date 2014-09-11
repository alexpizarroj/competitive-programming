#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char s[40];
    int ans, i, k, len;

    while ( true ) {
        // Entrada
        gets(s);
        if( strcmp(s, "0") == 0) break;
        len = strlen(s);
        // Resolucion
        ans = 0;
        for(i = len-1, k = 0; i != -1; i--, k++)
            if(s[i] != '0')
                ans += (s[i]-'0') * ( pow(2, k+1) - 1 );
        // Salida
        printf("%d\n", ans);
    }

    return 0;
}
