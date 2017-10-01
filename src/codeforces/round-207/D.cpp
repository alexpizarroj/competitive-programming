#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
using namespace std;

typedef long long ll;
const int cstMax = 1e6+100;
const int cstAlphaSize = 26;
char a[cstMax], b[cstMax];
int c[cstMax][cstAlphaSize];

ll getGcd(ll a, ll b)
{
    ll r;
    while ( b != 0 ) r = a%b, a = b, b = r;
    return a;
}

int main()
{
    ll n, m;
    ll alen, blen, gcd, lcm;
    ll cycleValue, nCicles;
    
    while ( cin >> n >> m )
    {
        cin >> a >> b;
        alen = strlen(a);
        blen = strlen(b);
        gcd = getGcd(alen, blen);
        lcm = alen / gcd * blen;
        
        cycleValue = lcm;
        nCicles = n * alen / lcm;
        
        memset(c, 0, sizeof c);
        fup(i,0,alen) ++c[i%gcd][int(a[i]-'a')];
        fup(i,0,blen) cycleValue -= c[i%gcd][int(b[i]-'a')];
        
        cout << ( cycleValue * nCicles ) << endl;
    }
    
    return 0;
}
