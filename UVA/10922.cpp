#include <stdio.h>
#include <string.h>
#include <memory.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, cnt, sum, i;
    char s[1001];
    memset(s, 0, 1001);

    while ( true ) {
        // Entrada
        gets(s);
        n = strlen(s);
        s[n] = 0;
        if(s[0] == '0' && n == 1) break;
        printf("%s", s);
        // Resolucion
        cnt = 1;
        while ( n != 1 ) {
            for (i = 0, sum = 0; i != n; i++) sum += s[i]-'0';
            n = sprintf(s, "%d", sum);
            s[n] = 0;
            if(n != 1) cnt++;
        }
        // Salida
        if(sum == 9)
            printf(" is a multiple of 9 and has 9-degree %d.\n", cnt);
        else
            printf(" is not a multiple of 9.\n", cnt);

    }

    return 0;
}
