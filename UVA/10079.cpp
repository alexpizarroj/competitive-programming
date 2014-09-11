#include <stdio.h>
#define ULL unsigned long long
#define VSIZE 210000000
//#define BRUTEFORCE

using namespace std;

ULL v[VSIZE+1];
const ULL PRECALC = 210000;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ULL i, i2, k3; int j, n, k1, k2;

    #ifndef BRUTEFORCE
    j = PRECALC+1;
    #else
    j = VSIZE+1;
    #endif
    v[0] = 1;
    for(i = 1; i != j; i++) v[i] = v[i-1] + i;
    #ifndef BRUTEFORCE
    k3 = v[PRECALC-1] - 1;
    #endif


    while ( scanf("%d", &j) != EOF ) {
        if ( j < 0 ) break;
        #ifndef BRUTEFORCE
        if ( j < PRECALC ) {
            printf("%llu\n", v[j]);
        } else {
            k1 = (j / PRECALC);
            k2 = (j % PRECALC);
            i = 1; n = 0;
            while (k1--) {
                n += PRECALC;
                i += PRECALC * n - k3;
            }
            i2 = n+1; n += k2;
            for(; i2 != n+1; i2++) i += i2;
            //
            printf("%llu\n", i);
        }
        #else
        printf("%llu\n", v[j]);
        #endif
    }

    return 0;
}
