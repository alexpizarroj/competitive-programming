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
#define PB 				        push_back
#define F                       first
#define S                       second
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define dall(a)		 	        (a).begin(), (a).end()
#define dinit(a) 		        memset(a, -1, sizeof(a))
#define dclr(a)         	 	memset(a, 0, sizeof(a))
#define dbet(lb,v,ub)			(lb <= v && v <= ub)
using namespace std; const int INF = int(1E9+7);
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> ii; typedef vector<int> vi;

class UnionFind
{
    vi p, rank;
public:
    UnionFind(int n = 0)
    {
        init(n);
    }
    void unionSet(int x, int y)
    {
        if( !isSameSet(x,y) )
        {
            x = findSet(x), y = findSet(y);
            if( rank[x] > rank[y] )
                p[y] = x;
            else
            {
                p[x] = y;
                if( rank[x] == rank[y] ) rank[y]++;
            }
        }
    }
    void init(size_t n)
    {
        p.resize(n); rank.assign(n, 0);
        for(size_t i = 0; i < n; i++) p[i] = i;
    }
    int findSet(int x)
    {
        if( p[x] == x ) return x; return p[x] = findSet(p[x]);
    }
    bool isSameSet(int x, int y)
    {
        return findSet(x) == findSet(y);
    }
};
typedef pair<int, ii> Edge;
Edge v[200005];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int m, n, totalCost, newCost;
	UnionFind uf;

	while ( scanf("%d %d", &m, &n), (m || n) )
	{
	    uf.init(n);
	    totalCost = newCost = 0;

	    fup(i,0,n)
	    {
	        scanf("%d %d %d", &v[i].S.F, &v[i].S.S, &v[i].F);
	        totalCost += v[i].F;
	    }
        sort(v, v + n);

        for(int i = 0; i < n; i++)
        {
            const ii &ref = v[i].S;
            if( !uf.isSameSet( ref.F, ref.S ) )
            {
                uf.unionSet( ref.F, ref.S );
                newCost += v[i].F;
            }
        }

        printf("%d\n", totalCost - newCost);
	}

    return 0;
}
