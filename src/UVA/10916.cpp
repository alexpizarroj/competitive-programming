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


int Benchmark(int b)
{
    int i=1;
    long double left=0, right=b*log10(2);
	
    while( left <= right )
        i++, left += log10(i);
  
    return i-1;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int y,b;
    map<int,int> cache;

    while( scanf("%d",&y), y )
    {
        y /= 10, y = y-194, b = pow(2,y);
        if( cache.count(b) == 0 ) cache[b] = Benchmark(b);
        printf("%d\n", cache[b]);
    }

    return 0;
}
