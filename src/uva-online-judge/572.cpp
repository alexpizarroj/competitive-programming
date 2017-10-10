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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int m,n;
char mz[100][101];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};

void dfs(int r, int c)
{
    int i,j;

    mz[r][c]='*';
    for(int k=0; k<8; k++)
    {
        i=r+dx[k], j=c+dy[k];
        if( inrange(0,i,m-1) && inrange(0,j,n-1) && mz[i][j]=='@' )
            dfs(i,j);
    }
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

	int i,j,cnt;

    while( scanf("%d %d", &m, &n), getchar(), m!=0 )
    {
        FOR(i,m) gets(mz[i]);

        cnt=0;
        FOR(i,m)
            FOR(j,n)
                if( mz[i][j]=='@' )
                {
                    dfs(i,j);
                    cnt++;
                }

        printf("%d\n", cnt);
    }

    return 0;
}
