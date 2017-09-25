#include <ctime>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <numeric>

#define pb              push_back
#define all(a)          (a).begin(), (a).end()
#define forn(i, n)      for(int i = 0; i < int(n); ++i)
#define fore(i, a, b)   for(int i = int(a); i <= int(b); ++i)
#define foreach(it, a)  for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)

using namespace std;

const int inf = 1000000007;
const int MAX = 100000;
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef long long       i64;
typedef vector<i64>     vi64;

vi mu;
void getMu(int mx)
{
    int lim = (int)floor(sqrt(mx));
    mu.assign(mx+1, 1);
    for(int i = 2; i <= lim; i++)
    {
        if ( mu[i] == 1 )
        {
            for(int j = i;   j <= mx; j += i)   mu[j] *= -i;
            for(int j = i*i; j <= mx; j += i*i) mu[j] = 0;
        }
    }
    for(int i = 2; i <= mx; i++)
    {
        if ( mu[i] == i )       mu[i] = 1;
        else if ( mu[i] == -i ) mu[i] = -1;
        else if ( mu[i] < 0 )   mu[i] = 1;
        else if ( mu[i] > 0 )   mu[i] = -1;
    }
}

int modpow(int a, int e)
{
    i64 res = 1, acc = a;
    while ( e > 0 )
    {
        if ( e&1 )
        {
            res = res * acc % inf;
        }
        acc = acc * acc % inf;
        e >>= 1;
    }
    return (int)res;
}

int fact[MAX+5], revf[MAX+5];
int getComb(int n, int k)
{
    if ( n < k ) return 0;
    return ((i64)fact[n] * revf[n-k] % inf) * revf[k] % inf;
}

int main()
{
    getMu(MAX+5);
    fact[0] = revf[0] = 1;
    fore(i,1,MAX) 
    {
        fact[i] = ( (i64)fact[i-1] * i ) % inf;
        revf[i] = modpow(fact[i], inf-2);
    }
    
    int Q;
    scanf("%d", &Q);
    while ( Q-- )
    {
        int n, f;
        scanf("%d %d", &n, &f);
        i64 ans = 0;
        for(int lim = (int)floor(sqrt(n)), i = 1; i <= lim; i++)
        {
            if ( n%i != 0 ) continue;
            int j = n/i;
            ans = (ans + mu[i] * getComb(j-1,f-1) + inf) % inf;
            if ( j == i ) continue;
            ans = (ans + mu[j] * getComb(i-1,f-1) + inf) % inf;
        }
        printf("%d\n", (int)ans);
    }
    
    return 0;
}
