#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <list>
#include <sstream>
#include <string>
#include <cstring>

#include <memory.h>
#include <algorithm>
#include <cmath>

#define FORX(i,start,end) for(i=start;i<end;i++)
#define FORY(i,start,end) for(i=start;i<=end;i++)

using namespace std;

inline long long sqr(long long n) { return n*n; }
long long bigMod(long long b, long long e, long long m)
{
    if( e == 0 ) return 0;
    else if ( e == 1 ) return b;

    if( e%2 == 0 )
    {
        return sqr( bigMod(b,e/2,m)%m )%m;
    }
    else
    {
        return (b * bigMod(b, e-1, m)%m)%m;
    }
}

bool isPrime(int n)
{
    if( n == 1 ) return false;
    else if( n%2 == 0 ) return false;

    int lim = sqrt(n)+2, i;
    for(i = 3; i < lim; i+=2)
        if( n%i==0 ) return false;

    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int p, a;
    long long k;
    bool prime;

    while ( scanf("%d %d", &p, &a) != EOF && p != 0 )
    {
        k = a%p;
        prime = isPrime(p);
        if( !prime && bigMod(k, p, p) == k )
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
