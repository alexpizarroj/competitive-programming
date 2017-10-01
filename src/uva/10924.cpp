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
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define LEN(a) (int)(a).length()
#define SQR(a) (a)*(a)
#define PB push_back
#define MP make_pair
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// }
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


#define MAXN 1500
bool prime[MAXN+1];
void Sieve()
{
	memset(prime, true, sizeof(prime));

	prime[0] = false;
	prime[1] = false;

	for(int i=2; i*i<=MAXN; i++)
		if(prime[i])
			for(int j=i*i; j<=MAXN; j+=i)
				prime[j] = false;
}

char s[21];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int sum,i,n;

    Sieve();
    while( gets(s) )
    {
        sum=0;
        n=strlen(s);

        FOR(i,n)
            if( isupper(s[i]) )
                sum += s[i]-'A'+27;
            else
                sum += s[i]-'a'+1;

        if( sum==1 || prime[sum] )
            puts("It is a prime word.");
        else
            puts("It is not a prime word.");
    }

    return 0;
}
