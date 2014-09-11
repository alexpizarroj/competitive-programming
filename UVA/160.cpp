// includes {
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
// }
using namespace std;
// defines {
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define TOK(pc, s, tokens) for(char* pc = strtok(s, tokens); pc != NULL; pc = strtok(NULL,tokens))
#define SZ(a) (int)(a).size()
#define LEN(a) (int)(a).length()
#define PB push_back
#define MP make_pair
#define all(a) (a).begin(), (a).end()
#define sqr(a) (a)*(a)
#define inrange(lb,i,ub) ((lb) <= (i) && (i) <= (ub))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// }
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};


#define MAXN 100
bool prime[MAXN+1];
vector<int> primes;
void Sieve()
{
	memset(prime, true, sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for(int i=2; i*i<=MAXN; i++)
		if(prime[i])
			for(int j=i*i; j<=MAXN; j+=i)
				prime[j] = false;

    primes.reserve(1300);
    for(int i=2; i<=MAXN; i++)
        if( prime[i] ) primes.push_back(i);
}

vector<int> factors;
int FactorialPrimeFact(const int n, vector<int>& v)
{
    int cnt=0;
    for(int i=0; primes[i]<=n && i<SZ(primes); i++)
    {
        const int& p = primes[i];
        double q = (n/(double)p);
        int d = int(q);

        while (q >= p)
            q /= p, d += int(q);

        v[cnt++] = d;
    }
    return cnt;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int n, k, i, cnt;
	Sieve();
	factors.reserve(1300);

	while( scanf("%d", &n), n!=0 )
	{
		printf("%3d! =", n);
		k = FactorialPrimeFact(n, factors);
		for(i=0,cnt=0; i<k; i++, cnt++)
		{
			if( cnt==15 )
			{
				cnt=0;
				printf("\n      ");
			}
			printf("%3d", factors[i]);
		}
		puts("");
	}

    return 0;
}
