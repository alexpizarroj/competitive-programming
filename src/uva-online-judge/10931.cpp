#include <stdio.h>
#include <memory.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char b[32], *sp;
    int n, sum, i, len;
    memset(b, 0, 32);

    while( true ) {
        // Break
        scanf("%d", &n);
        if(n == 0) break;
        // Resolucion
        sum = 0;
        i = 30;
        len = 0;
        while( n != 0 ) {
            b[i--] = (n & 1 ? '1' : '0');
            n >>= 1;
            len++;
        }
        sp = &(b[i+1]);
        for(i = 0; i != len; i++)
            if( sp[i]=='1' ) sum++;
        // Salida
        printf("The parity of %s is %d (mod 2).\n", sp, sum);
    }

    return 0;
}
