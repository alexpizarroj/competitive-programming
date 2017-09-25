#include <ctime>
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
#include <numeric>

#define pb              push_back
#define all(a)          (a).begin(), (a).end()
#define forn(i, n)      for(int i = 0; i < int(n); ++i)
#define fore(i, a, b)   for(int i = int(a); i <= int(b); ++i)
#define foreach(it, a)  for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)

using namespace std;

const int inf = int(1e9+7);
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef long long       i64;
typedef vector<i64>     vi64;

const int maxn = 500010;
int n, a[maxn];
struct TreeNode
{
    int minelem;
    
    void update(int i)
    {
        this->minelem = a[i];
    }
    
    void update(const TreeNode &le, const TreeNode &ri)
    {
        this->minelem = min(le.minelem, ri.minelem);
    }
};
TreeNode T[4*maxn];

void update(int b, int e, int node, int i, int val)
{
    if( i < b || i > e ) return;
    
    if( b == e ) a[i] = val, T[node].update(i);
    else
    {
        int mid = (b + e)/2, le = 2*node+1, ri = 2*node+2;
        update(b, mid, le, i, val);
        update(mid + 1, e, ri, i, val);
        T[node].update(T[le], T[ri]);
    }
}
inline void update(int i, int val) { update(0, n-1, 0, i, val); }

void init(int b, int e, int node)
{
    if(b == e) T[node].update(b);
    else
    {
        int mid = (b + e)/2, le = 2*node+1, ri = 2*node+2;
        init(b, mid, le);
        init(mid+1, e, ri);
        T[node].update(T[le], T[ri]);
    }
}
inline void init() { init(0, n-1, 0); }

TreeNode query(int b, int e, int node, int i, int j)
{
    if(i <= b && e <= j) return T[node];
    
    int mid = (b + e) / 2, le = 2*node + 1, ri = 2*node + 2;
    TreeNode ret;
    
    if(j <= mid)        ret = query(b, mid, le, i, j);
    else if(mid < i)    ret = query(mid + 1, e, ri, i, j);
    else
    {
        TreeNode ret1, ret2;
        ret1 = query(b, mid, le, i, j);
        ret2 = query(mid + 1, e, ri, i, j);
        ret.update(ret1, ret2);
    }
    return ret;
}
inline TreeNode query(int i, int j) { return query(0, n-1, 0, i, j); }

int main()
{
	scanf("%d", &n);
	forn(i,n) scanf("%d", a+i);
	init();
	char oper[10];
	int op1, op2;
	while ( scanf("%s %d %d", oper, &op1, &op2) != EOF )
		if ( oper[0] == 's' )
			update(op1-1, op2);
		else
			printf("%d\n", query(op1-1, op2-1).minelem);
    return 0;
}
