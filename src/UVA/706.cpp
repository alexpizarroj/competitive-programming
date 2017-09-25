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


struct Digit {
    Digit() {}
    Digit(bool _top, bool _mid, bool _bot, bool _ltop, bool _lbot, bool _rtop, bool _rbot)
    {
        top = _top; mid = _mid; bot = _bot;
        ltop = _ltop; lbot = _lbot;
        rtop = _rtop; rbot = _rbot;
    }
    bool top, mid, bot, ltop, lbot, rtop, rbot;
};
Digit D[10];

void InitMap()
{
    //           horizontales  ver. izq   ver. der
    D[0] = Digit(1,0,1,        1,1,       1,1);
    D[1] = Digit(0,0,0,        0,0,       1,1);
    D[2] = Digit(1,1,1,        0,1,       1,0);
    D[3] = Digit(1,1,1,        0,0,       1,1);
    D[4] = Digit(0,1,0,        1,0,       1,1);
    D[5] = Digit(1,1,1,        1,0,       0,1);
    D[6] = Digit(1,1,1,        1,1,       0,1);
    D[7] = Digit(1,0,0,        0,0,       1,1);
    D[8] = Digit(1,1,1,        1,1,       1,1);
    D[9] = Digit(1,1,1,        1,0,       1,1);
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int s,R,C;
    int i,j,k,len;
    int top, mid, bot;
    char n[10];
    bool horizontal, topHalf, botHalf;
    bool dontPrint;

	InitMap();
	SET(n,0);

	while( scanf("%d %s", &s, n), !(s == 0 && strcmp(n,"0") == 0) )
	{
        R = 2*s + 3; C = s+2;
        top = 0;
        mid = 1+s;
        bot = R-1;

        len = strlen(n);
        FOR(i,R)
        {
            horizontal = ( i==0 || i==1+s || i==R-1 );
            topHalf = ( i > 0   && i < 1+s );
            botHalf = ( i > 1+s && i < R-1 );
            FOR(k,len)
            {
                Digit &dig = D[ n[k]-'0'] ;
                if(k>0) printf(" ");
                FOR(j,C)
                {
                    dontPrint = horizontal && (j==0 || j==C-1);
                    dontPrint = dontPrint || (!horizontal && ( j > 0 && j < C-1 ));
                    if( !dontPrint && horizontal )
                    {
                        if( i==top )
                            dontPrint = dontPrint || ( !dig.top );
                        else if( i==mid )
                            dontPrint = dontPrint || ( !dig.mid );
                        else
                            dontPrint = dontPrint || ( !dig.bot );
                    }
                    else if( !dontPrint )
                    {
                        if( topHalf )
                        {
                            if( j==0 )
                                dontPrint = dontPrint || ( !dig.ltop );
                            else
                                dontPrint = dontPrint || ( !dig.rtop );
                        }
                        else if ( botHalf )
                        {
                            if( j==0 )
                                dontPrint = dontPrint || ( !dig.lbot );
                            else
                                dontPrint = dontPrint || ( !dig.rbot );
                        }
                    }

                    if( !dontPrint )
                        printf(horizontal ? "-" : "|");
                    else
                        printf(" ");
                }
            }
            puts("");
        }

        puts("");
	}

    return 0;
}
