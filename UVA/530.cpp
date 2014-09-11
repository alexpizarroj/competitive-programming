#include <stdio.h>

using namespace std;


int gcd(int a, int b) {
    if (a%b==0) return b; else return gcd(b,a%b);
}

void divByGcd(int &a, int &b) {
    int g=gcd(a,b);
    a/=g;
    b/=g;
}

int C(int n,int k) {
    int numerator=1,denominator=1,toMul,toDiv,i;
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

    int n, k;
    while ( true ) {
        scanf("%d %d", &n, &k);
        if( !(n+k) ) break;
        printf("%d\n", C(n, k));
    }

    return 0;
}
