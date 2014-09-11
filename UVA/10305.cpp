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

#define MAX 101
int deg[MAX], edge[MAX][MAX];
bool root[MAX], visited[MAX];
bool first_node_printed;

void dfs(int node)
{
    if( visited[node] ) return;

    visited[node] = true;
    if( first_node_printed )
    {
        printf("%d", node);
        first_node_printed=false;
    }
    else
        printf(" %d", node);
    for(int k=0; k<deg[node];k++)
        dfs( edge[node][k] );
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int n,m,v,w,i;

    while( scanf("%d %d",&n,&m), !(n==0 && m==0) )
    {
        SET(deg,0);
        SET(root,1);
        REP(i,m)
        {
            scanf("%d %d", &v, &w);
            edge[v][ deg[v]++ ] = w;
            root[w]=false;
        }

        SET(visited,0);
        first_node_printed=true;
        REP(i,n)
            if( root[i] ) dfs(i);
        puts("");
    }

    return 0;
}

// ====================
//  SIMULATION (NO DFS)
// ====================
//
//set<int> req[101];
//bool printed[101];
//
//int main() {
//	#ifndef ONLINE_JUDGE
//    freopen("data.in", "r", stdin);
//	#endif
//
//    int n,m,i,v,w;
//    set<int> taken;
//
//    while( scanf("%d %d",&n,&m), !(n==0 && m==0) )
//    {
//        REP(i,n) req[i].clear();
//        REP(i,m)
//        {
//            scanf("%d %d", &v, &w);
//            req[w].insert(v);
//        }
//
//        w = n;
//        SET(printed,false);
//        while( w > 0 )
//        {
//            taken.clear();
//            REP(i,n)
//            {
//                if( !printed[i] && req[i].empty() )
//                {
//                    taken.insert(i);
//                    printed[i] = true;
//
//                    if( w-- != n ) printf(" ");
//                    printf("%d", i);
//                }
//            }
//            REP(i,n)
//                if( !printed[i] && req[i].size() > 0 )
//                    foreach(it, taken)
//                        req[i].erase(*it);
//        }
//        puts("");
//    }
//
//    return 0;
//}
