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
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct State_t { int a,b,c,d; };
bool operator==(State_t x, State_t y)
{ return (x.a==y.a) && (x.b==y.b) && (x.c==y.c) && (x.d==y.d); }
typedef pair<State_t,int> psi;

bool visited[10][10][10][10];
const int da[] = {1,-1,0,0,0,0,0,0};
const int db[] = {0,0,1,-1,0,0,0,0};
const int dc[] = {0,0,0,0,1,-1,0,0};
const int dd[] = {0,0,0,0,0,0,1,-1};

inline bool IsVisited(const State_t& s)
{ return visited[s.a][s.b][s.c][s.d]; }

inline void MarkAsVisited(const State_t& s)
{ visited[s.a][s.b][s.c][s.d] = true; }

inline int Adjust(int v)
{
    if( v==10 ) return 0;
    else if( v==-1 ) return 9;
    else return v;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

	int N,n,cost;
	queue<psi> q;
    State_t ini, tar, cfg, tmp_cfg;

	scanf("%d",&N);
	while(N--)
	{
        scanf("%d %d %d %d", &ini.a, &ini.b, &ini.c, &ini.d);
        scanf("%d %d %d %d", &tar.a, &tar.b, &tar.c, &tar.d);

        scanf("%d",&n);
        SET(visited,false);
        while(n--)
        {
            scanf("%d %d %d %d", &cfg.a, &cfg.b, &cfg.c, &cfg.d);
            MarkAsVisited(cfg);
        }

        while( !q.empty() ) q.pop();
        q.push( MP(ini,0) );
        MarkAsVisited(ini);

        while( !q.empty() )
        {
            cfg = q.front().first;
            cost = q.front().second;
            q.pop();
            if( cfg == tar ) break;

            for(int i=0;i<8;i++)
            {
                tmp_cfg.a = Adjust(cfg.a + da[i]);
                tmp_cfg.b = Adjust(cfg.b + db[i]);
                tmp_cfg.c = Adjust(cfg.c + dc[i]);
                tmp_cfg.d = Adjust(cfg.d + dd[i]);
                if( !IsVisited(tmp_cfg) )
                {
                    q.push( MP(tmp_cfg,cost+1) );
                    MarkAsVisited(tmp_cfg);
                }
            }
        }

        if( cfg == tar )
            printf("%d\n", cost);
        else
            puts("-1");
	}

    return 0;
}
