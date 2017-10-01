#include <stdio.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#define BESTLEN 101

using namespace std;


inline int cton(char c) {
    if(c > 64) return c-55;
    return c-48;
}

inline char ntoc(int n) {
    if(n < 10) return (char)(n+48);
    return (char)n+55;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char s[BESTLEN], n[8];
    int i, j, len, bfrom, bto, dec = 0;
    bool error;

    memset(s, 0, BESTLEN);
    memset(n, 0, 8);
    while ( gets(s) ) {
        // Entrada
        sscanf(s, "%s %d %d", n, &bfrom, &bto);
        // Conversión a decimal
        len = strlen(n); dec = 0;
        for(i = 0, j = len-1; i != len; i++, j--)
            dec += cton(n[i]) * pow(bfrom, j);
        error = false;
        // Conversión a base pedida
        if(bto != 10) {
            memset(n, ' ', 7); n[7] = 0;
            i = 6;
            while (dec >= bto && i != -1) {
                n[i--] = ntoc(dec%bto);
                dec /= bto;
            }
            if(i == -1) error = true; else n[i] = ntoc(dec);
        } else {
            error = (dec > 9999999);
        }
        // Salida
        if(error) { printf("  ERROR\n"); continue; }
        if(bto == 10) printf("%7d\n", dec);
        else printf("%s\n", n);
    }

    return 0;
}

