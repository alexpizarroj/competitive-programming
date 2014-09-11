#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long Num;

inline Num gcd(Num a, Num b) { Num r; while ( b != 0 ) r = a%b, a = b, b = r; return a; }

inline void div_by_gcd(Num &a, Num &b) { Num g = gcd(a,b); a /= g, b /= g; }

Num C(int n,int k){
    Num numerator=1,denominator=1,toMul,toDiv;
    int i;
    if (k>n/2) k=n-k; /* use smaller k */
    for (i=k;i;i--) {
        toMul = n-k+i, toDiv = i;
        /* always divide before multiply */
        div_by_gcd(toMul,toDiv);
        div_by_gcd(numerator,toDiv);
        div_by_gcd(toMul,denominator);
        //
        numerator *= toMul, denominator *= toDiv;
    }
    return numerator/denominator;
}

vector<Num> nSpoons; // numbers of spoons using up to [index] cities i.e. nSpoons[5] returns the maximun numbers of spoons that 5 cities can handle
void precalc()
{
    Num x = 1000000000000000000LL, r = 0;
    nSpoons = vector<Num>(2,0);
    int n = 1;
    do
    {
        n++;
        r = C(n,n/2);
        nSpoons.push_back( r );
    } while (r < x);
}

inline int getMin(Num x) { return distance(nSpoons.begin(), lower_bound(nSpoons.begin(), nSpoons.end(), x)); }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t; Num n;
	precalc();
	scanf("%d", &t);
	while (t--)
	{
	    scanf("%lld", &n);
	    printf("%d\n", getMin(n));
	}
    return 0;
}
