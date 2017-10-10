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


set<int> s;
vector<int> v;
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    double r;
    for(int w=0; w<=31; w++)
        for(int x=0; x<=20; x++)
            for(int y=0; y<=14; y++)
                for(int z=0; z<=12; z++)
                {
                    r = pow(2,w)*pow(3,x)*pow(5,y)*pow(7,z);
                    if( r <= 2000000000 ) s.insert( int(r) );
                }
    v.resize( s.size() );
    copy(ALL(s), v.begin());

    int n,d,d2;
    char suffix[3];
    while( scanf("%d", &n), n!=0 )
    {
        d=n%10; d2=(n/10)%10;
        if( d==1 && d2!=1 )
            strcpy(suffix, "st");
        else if ( d==2 && d2!=1 )
            strcpy(suffix, "nd");
        else if ( d==3 && d2!=1 )
            strcpy(suffix, "rd");
        else
            strcpy(suffix, "th");
        printf("The %d%s humble number is %d.\n", n, suffix, v[n-1] );
    }

    return 0;
}
