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

inline int f(int n)
{
    int sum=0,d;
    while(n>0)
        d=n%10, sum += d*d, n/=10;
    return sum;
}

set<int> s;
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int t,T,k,n;
    scanf("%d", &T);
    REP(t,T)
    {
        s.clear();
        scanf("%d", &n);
        k = n;
        while( k != 1 && s.count(k) == 0 )
        {
            s.insert(k);
            k = f(k);
        }
        printf("Case #%d: %d is a%s number.\n", t, n, (k == 1 ? " Happy" : "n Unhappy"));
    }

    return 0;
}
