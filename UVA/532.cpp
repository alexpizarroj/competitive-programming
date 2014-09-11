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
const int dx[] = {0, 0,1,-1,0, 0};
const int dy[] = {1,-1,0, 0,0, 0};
const int dz[] = {0, 0,0, 0,1,-1};

int l,r,c;
char mz[30][31][31];
struct Position {
    Position() {}
    Position(int _l, int _r, int _c) : l(_l), r(_r), c(_c) {}

    int l,r,c;

    bool operator==(const Position& b)
    { return (l==b.l && r==b.r && c==b.c); }
    Position clone()
    { return Position(l,r,c); }
};
Position pstart, pend;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int i,j,k,cost,minutes;
    bool fstart, fend;
    queue< pair<Position,int> > q;
    Position p1, p2;

	while( scanf("%d %d %d",&l,&r,&c), getchar(), !(l==r && r==c && c==0) )
	{
	    fstart=fend=false;
        FOR(i,l)
        {
            for(j=0; gets(mz[i][j]) != NULL && strlen(mz[i][j]) > 0; j++)
            {
                char *line = mz[i][j];

                if( !fstart )
                {
                    k = find(line,line+c,'S')-line;
                    if( k < c ) pstart = Position(i,j,k), fstart=true;
                }

                if( !fend )
                {
                    k = find(line,line+c,'E')-line;
                    if( k < c ) pend = Position(i,j,k), fend=true;
                }
            }
        }

        mz[pstart.l][pstart.r][pstart.c]='#';
        q.push( MP(pstart,0) );
        minutes = -1;
        while( !q.empty() )
        {
            p1 = q.front().first;
            cost = q.front().second;
            q.pop();

            if( p1==pend )
            {
                minutes = cost;
                while( !q.empty() ) q.pop();
                break;
            }

            for(k=0; k<6; k++)
            {
                p2.l = p1.l + dz[k];
                p2.r = p1.r + dx[k];
                p2.c = p1.c + dy[k];
                if( inrange(0,p2.l,l-1) && inrange(0,p2.r,r-1) && inrange(0,p2.c,c-1)
                   && mz[p2.l][p2.r][p2.c]!='#')
                {
                    mz[p2.l][p2.r][p2.c] = '#';
                    q.push( MP(p2.clone(), cost+1) );
                }
            }
        }

        if( minutes > -1 )
            printf("Escaped in %d minute(s).\n", minutes);
        else
            puts("Trapped!");
	}

    return 0;
}
