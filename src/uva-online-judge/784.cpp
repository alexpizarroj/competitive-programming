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
#define TOK(pc, s, tokens) for(char* pc = strtok(s, tokens); pc != NULL; pc = strtok(NULL,tokens))
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<double> vd;
typedef vector<dd> vdd;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


struct StaticString { char c[81]; int len; };
vector<StaticString> maze; int n;

const int movx[] = {0,0,1,-1};
const int movy[] = {1,-1,0,0};
void dfs(int r, int c)
{
    int tr, tc;
    maze[r].c[c] = '#';
    for(int k=0; k<4; k++)
    {
        tr = r+movx[k];
        tc = c+movy[k];
        if( 0 <= tr && tr < n && 0 <= tc && tc <= maze[tr].len
           && maze[tr].c[tc] == ' ' )
        {
            dfs(tr, tc);
        }
    }
}

char line[81];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int t,i;
    int cr,cc;
    bool gotStartPoint;
    maze.resize(31);

    scanf("%d", &t); getchar();
    while(t--)
    {
        n = gotStartPoint = 0;
        while( gets(maze[n].c), maze[n].len = strlen(maze[n].c),
          maze[n].c[0] != '_' )
        {
            if( !gotStartPoint )
            {
                cc = find(maze[n].c, maze[n].c+maze[n].len, '*') - maze[n].c;
                if( cc != maze[n].len )
                {
                    cr = n;
                    gotStartPoint=true;
                }
            }
            n++;
        }

        maze[cr].c[cc] = ' ';
        dfs(cr, cc);

        FOR(i,n) printf("%s\n", maze[i].c);
        printf("%s\n", maze[n].c);
    }

    return 0;
}
