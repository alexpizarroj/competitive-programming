#include <stdio.h>
#include <string.h>
#include <memory.h>
#define GN 11

using namespace std;


static int v[1001];

void init() {
    v[0] = 0%GN;
    v[1] = 1%GN;
    for(int i = 2; i != 1001; i++)
        v[i] = (v[i-1]*10)%GN;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char s[1001];
    int n, i, j, sum;
    memset(s, 0, 1001);
    init();

    while ( true ) {
        // Entrada
        gets(s);
        n = strlen(s);
        if(n == 1 && s[0] == '0') break;
        // Resolucion
        sum = 0;
        for(i = n-1, j = n; i != -1; i--, j--)
            sum += ( v[j]*(s[i]-'0') ) % GN;
        sum %= GN;
        // Salida
        if(sum == 0)
            printf("%s is a multiple of %d.\n", s, GN);
        else
            printf("%s is not a multiple of %d.\n", s, GN);
    }

    return 0;
}
