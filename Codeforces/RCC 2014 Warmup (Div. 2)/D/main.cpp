#include <cassert>
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
typedef pair<int,int> ii;
typedef vector<int> vi;

struct Friend
{
    int cost, mon, prob;
    bool operator<(const Friend &rhs) const
    {
        return this->mon < rhs.mon;
    }
};
Friend vec[105];
const long long INF = 5 * (long long)1e18;
long long dp[2][1048581];

int main()
{
    int n, m, b, nProblems, probId, cur, topMask;
    long long mincost;
    
    while ( cin >> n >> m >> b, cin )
    {
        fup(i,0,n)
        {
            scanf("%d %d %d", &vec[i].cost, &vec[i].mon, &nProblems);
            vec[i].prob = 0;
            fup(j,0,nProblems)
            {
                scanf("%d", &probId);
                vec[i].prob |= 1<<(probId-1);
            }
        }
        sort(vec, vec+n);
        
        topMask = (1<<m) - 1;
        fill(dp[0], dp[0]+topMask+1, INF);
        dp[0][0] = 0, cur = 1, mincost = INF;
        fup(sid,0,n)
        {
            fupi(mask,0,topMask)
            {
                dp[cur][mask] = min(dp[1-cur][mask], dp[1-cur][mask & (~vec[sid].prob)] + vec[sid].cost);
            }
            mincost = min(mincost, dp[cur][topMask] + vec[sid].mon*(long long)b);
            cur = 1 - cur;
        }
        cout << (mincost == INF ? -1 : mincost) << endl;
    }
	
    return 0;
}
