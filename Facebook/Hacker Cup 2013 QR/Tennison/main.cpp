#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;
const int INF = int(1E9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

const double UNTRIED = -1;
double dp[105][105][1005];
double ps, pr, pw, pl;
int pu, pd; // [0..1000]

// Chance of winning n sets loosing at most m sets,
// with p as the prob. of sun for the next match
double f(int n, int m, int p)
{
    if ( n == 0 ) return 1; // we won
    if ( m < 0 ) return 0; // we lost
    if ( dp[n][m][p] != UNTRIED ) return dp[n][m][p];

    double pi, v, wp, lp;

    pi = (double)p / 1000.0; // odds of having sun
    v = pi*ps + (1-pi)*pr; // odds of winning the set
    wp = pw*f(n-1,m,min(p+pu,1000)) + (1-pw)*f(n-1,m,p); // odds of winning the game after winning the set
    lp = pl*f(n,m-1,max(p-pd,0))    + (1-pl)*f(n,m-1,p); // odds of winning the game after losing the set

    return dp[n][m][p] = v*wp + (1-v)*lp;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t, k, caseNo = 1;
    int a, b, c, d, e, g, p;

    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d %lf %lf %d.%d %d.%d %lf %d.%d %lf",
              &k, &ps, &pr, &a, &b, &c, &d, &pw, &e, &g, &pl);

        fupi(i,0,k) fupi(j,0,k-1) fupi(h,0,1000) dp[i][j][h] = UNTRIED;
        p = a*1000 + b, pu = c*1000 + d, pd = e*1000 + g;
        printf("Case #%d: %.6lf\n", caseNo++, f(k, k-1, p));
    }

    return 0;
}
