#include <iostream>
#include <cstdio>
using namespace std;

const int cstMod = 1000000007;
typedef unsigned long long Number;

Number to_bin(int n)
{
    Number r = 0, mult = 1;
    while ( n > 0 ) r = mult*(n&1) + r, mult *= 10, n >>= 1;
    return r;
}

int modpow(int b, Number e, int m) // (b ** e) mod m
{
    Number A = (b%m), B = 1;
    while ( e > 0 )
    {
        if ( e&1 ) B = (B*A)%m;
        A = (A*A)%m;
        e >>= 1;
    }
    return B;
}

int main()
{
    int tc, n;
    Number root;
    
    scanf("%d", &tc);
    while ( tc-- )
    {
        scanf("%d", &n);
        root = modpow(2,to_bin(n),cstMod);
        printf("%d\n", int((root*root)%cstMod) );
    }
    
    return 0;
}
