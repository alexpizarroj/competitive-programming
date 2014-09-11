#include <stdio.h>
#define INT long long

using namespace std;


INT gcd(INT a, INT b) {
    if (a%b==0) return b; else return gcd(b,a%b);
}

void divByGcd(INT &a, INT &b) {
    int g=gcd(a,b);
    a/=g;
    b/=g;
}

INT C(INT n,INT k) {
    INT numerator=1,denominator=1,toMul,toDiv,i;
    if (k>n/2) k=n-k; /* use smaller k */
    for (i=k;i;i--) {
        toMul=n-k+i;
        toDiv=i;
        divByGcd(toMul,toDiv); /* always divide before multiply */
        divByGcd(numerator,toDiv);
        divByGcd(toMul,denominator);
        numerator*=toMul;
        denominator*=toDiv;
    }
    return numerator/denominator;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    INT n, k;
    while ( true ) {
        scanf("%lld %lld", &n, &k);
        if( !(n+k) ) break;
        printf("%lld things taken %lld at a time is %lld exactly.\n", n, k, C(n, k));
    }

    return 0;
}
