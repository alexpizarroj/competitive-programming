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

#define EPS 10E-6

inline bool isInt(double d)
{ return (d == d) && ( fabs( ceil(d)-d ) < EPS ); }

inline bool isPosInt(double d)
{ return (isInt(d) && d > 0); }

inline pair<double,double> getRoots(double a, double b, double c)
{
    double x1, x2;
    double d = b*b-4*a*c;

    x1 = (-b+sqrt(d))/(2*a);
    x2 = (-b-sqrt(d))/(2*a);

    return MP(x1, x2);
}

int main() {
    /*
	int found=0;
	ll current=1,leftSum,rightSum,n,n2;
	dd rt;

	while ( found < 10 )
	{
	    rt.first = 0.1, rt.second = 0.1;
	    while( 1 )
	    {
	        current++;
            leftSum = (current*(current-1))/2;
            rt = getRoots(1, 2*current+1, -2*leftSum);
            if( isPosInt(rt.first) )
            {
                n = (ll)ceil(rt.first);
                rightSum = (n*(2*(current+1)+n-1))/2;
                if( leftSum == rightSum ) break;
            }
	    }

	    printf("%10lld%10lld\n", current, current+(ll)n);
        found++;
	}
	*/

	puts("         6         8");
    puts("        35        49");
    puts("       204       288");
    puts("      1189      1681");
    puts("      6930      9800");
    puts("     40391     57121");
    puts("    235416    332928");
    puts("   1372105   1940449");
    puts("   7997214  11309768");
    puts("  46611179  65918161");

    return 0;
}

// ALTERNATIVE SOLUTION
/*
#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    long long actual, lastone = 2;
    unsigned long long abajo,arriba;
    //S=((u1+un)*n)/2
        
    for (int i=1; i<1000000000; i++) {
        actual = i;
        do
        {
            abajo = (actual * (actual-1) ) /2;
            arriba = ((actual+1+lastone) * (lastone - actual)) / 2;
            if  ( abajo == arriba )
            {
				printf("%10lld%10lld\n",actual,lastone);
                actual++;
            }
            else
            {
                lastone++;
            }

        } while (abajo >= arriba );
    }
	
    return 0;
}
*/