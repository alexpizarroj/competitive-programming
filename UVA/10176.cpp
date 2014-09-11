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

#define MOD 131071
char bin[10001];

int ModExp(const int b, int e, const int m)
{
    if( e==0 )
        return 1%m;
    if( (e&1)==1 )
        return int((ModExp(b,e-1,m)%m * (ll)(b%m))%m);
    else
    {
        ll v = ModExp(b,e/2,m);
        return int((v*v)%m);
    }
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    char c;
    int len=0,rem,i,j;

    while( scanf("%c",&c)==1 )
    {
        if( c == '\n' ) continue;
        if( c == '#') {
            bin[len] = '\0';

            rem=0;
            for(i=len-1,j=0; i>=0; i--,j++)
                rem = ( rem + ( (bin[i]-'0') * ModExp(2,j,MOD) )%MOD )%MOD;

            if( rem==0 )
                puts("YES");
            else
                puts("NO");
            len = 0;
        }
        else
            bin[len++] = c;
    }

    return 0;
}
