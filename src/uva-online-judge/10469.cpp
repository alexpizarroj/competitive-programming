#include <stdio.h>
#include <memory.h>
#include <math.h>
#define BITS 32
#define UINT unsigned int

using namespace std;


void fill(char* s, UINT n) {
    for(int i = 31; i != -1; i--) {
        s[i] = ( n&1 ? '1' : '0' );
        n >>= 1;
    }
    s[32] = 0;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    UINT a, b, c; int i, j;
    char s1[BITS+1], s2[BITS+1];
    bool bit1, bit2;

    while ( scanf("%u %u", &a, &b) != EOF ) {
        // Conversion a binario
        c = 0;
        memset(s1, '0', BITS+1);
        memset(s2, '0', BITS+1);
        fill(s1, a);
        fill(s2, b);
        // Resolucion
        for(i = 31, j = 0; i != -1; i--, j++) {
            bit1 = (bool)(s1[i]-'0');
            bit2 = (bool)(s2[i]-'0');
            if( bit1^bit2 ) c += pow(2, j);
        }
        printf("%u\n", c);
    }

    return 0;
}
