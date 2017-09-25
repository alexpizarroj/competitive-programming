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
const int INF = int(1e9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

vector<vi> graph;
int fch[1005], pt[1005], memo[1005];

void dfsChildren(int u)
{
    fch[u] = 0;
    fup(i,0,graph[u].size())
    {
        int v = graph[u][i];
        if ( pt[u] != v )
        {
            pt[v] = u;
            dfsChildren(v);
            fch[u] += fch[v]+1;
        }
    }
}

int getcost(int u)
{
    if ( memo[u] != -1 ) return memo[u];
    
    int ans = 0, nChildren = graph[u].size() + (pt[u] != -1 ? -1 : 0);
    if ( nChildren == 1 )
    {
        fup(i,0,graph[u].size())
        {
            int v = graph[u][i];
            if ( pt[u] == v ) continue;
            ans += fch[v]+1;
        }
    }
    else if ( nChildren >= 2 )
    {
        int max1, max2, v1, v2;
        max1 = max2 = v1 = v2 = -INF;
        fup(i,0,graph[u].size())
        {
            int v = graph[u][i];
            if ( pt[u] == v ) continue;
            int k = (fch[v]+1) - getcost(v);
            // ===============================
            if ( k > max1 )
            {
                max2 = max1, v2 = v1;
                max1 = k,    v1 = v;
            } else if ( k > max2 )
            {
                max2 = k,    v2 = v;
            }
        }
        assert(max1 >= max2 && max2 >= -INF);
        assert(v1 != v2 && v1 != -INF && v2 != -INF);
        fup(i,0,graph[u].size())
        {
            int v = graph[u][i];
            if ( pt[u] == v || v == v1 || v == v2 ) continue;
            // ===============================
            ans += fch[v]+1;
        }
        ans += getcost(v1) + getcost(v2);
    }
    
    return memo[u] = ans;
}

int main()
{
    int tc;
    cin >> tc;
    fupi(caso,1,tc)
    {
        printf("Case #%d: ", caso);
        int n, x, y;
        cin >> n;
        graph.assign(n, vi());
        fup(i,0,n-1)
        {
            cin >> x >> y;
            --x, --y;
            graph[x].PB(y);
            graph[y].PB(x);
        }
        int ans = INF, usedRoot, cand;
        fup(i,0,n)
        {
            memset(pt, -1, sizeof pt);
            memset(memo, -1, sizeof memo);
            dfsChildren(i);
            assert(fch[i]+1 == n);
            cand = getcost(i);
            assert(cand < n);
            if ( cand < ans )
            {
                ans = cand;
                usedRoot = i;
            }
        }
        assert(ans < n);
        printf("%d\n", ans);
        //printf("Used Root %d\n", usedRoot+1);
    }
	
    return 0;
}
