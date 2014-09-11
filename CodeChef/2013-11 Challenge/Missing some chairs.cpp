#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int cstMod = 1000000007;

int modpow(int b, int e, int m) // (base ** exponent) mod m
{
    if ( e == 0 ) return 1;
    long long root = modpow(b, e/2, m);
    return (((root * root)%m) * ( e&1 ? b%m : 1))%m;
}

int main()
{
    int tc, n;
    scanf("%d", &tc);
    while ( tc-- )
    {
        scanf("%d", &n);
        printf("%d\n", modpow(2,n,cstMod)-1);
    }
    return 0;
}
