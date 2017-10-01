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
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define PB push_back
#define MP make_pair
#define PI acos(-1)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define range(v) (v).begin(), (v).end()
#define len(a) (int)(a).length()
#define sz(a) (int)(a).size()
#define sqr(a) (a)*(a)
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const string HINT = "2147483647";
inline string removeLZ(const string &s)
{
    int i;
    for(i=0; s[i]=='0'; i++);
    return s.substr(i,len(s)-i);
}
inline bool greaterThanMax(const string &s)
{
    if( len(s) < len(HINT) ) return false;
    return ( len(s) > len(HINT) || s > HINT );
}

char line[1001];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    string val1, val2, op;
    int i1, i2; ll result;
    bool g1, g2, g3;

    while( gets(line) )
    {
        stringstream dat;
        dat << line;
        dat >> val1 >> op >> val2;

        g1 = greaterThanMax( removeLZ(val1) );
        g2 = greaterThanMax( removeLZ(val2) );
        g3 = false;
        if( g1 || g2 )
            g3 = true;
        else
        {
            sscanf(val1.c_str(), "%d", &i1);
            sscanf(val2.c_str(), "%d", &i2);
            if( op == "+" )
                result = (ll)i1 + i2;
            else
                result = (ll)i1 * i2;
            g3 = ( result > INT_MAX );
        }
        if( val1=="0" || val2=="0" ) g3=false;

        printf("%s\n", line);
        if( g1 ) puts("first number too big");
        if( g2 ) puts("second number too big");
        if( g3 ) puts("result too big");
    }

    return 0;
}
