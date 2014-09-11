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
typedef long long       i64;
typedef vector<i64>     vi64;

const int maxn = (1e6)+7;
int n, a[maxn];
struct TreeNode
{
    int minpos, sum;
    
    void update(int i)
    {
        this->minpos = ( a[i] == 0 ? i : inf );
        this->sum = a[i];
    }
    
    void update(const TreeNode &le, const TreeNode &ri)
    {
        this->minpos = min(le.minpos, ri.minpos);
        this->sum = le.sum + ri.sum;
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

struct Event
{
    int start, end, val, expected;
    
    Event(int ss, int ee, int vv, int exx)
        : start(ss), end(ee), val(vv), expected(exx) { }
        
    bool operator<(const Event& rhs) const
    {
        if ( end != rhs.end ) return end < rhs.end;
        return val < rhs.val;
    }
};
int lastseen[maxn], sol[maxn];
vector<Event> events;

int find(int b)
{
    int lo = 0, hi = n-1, node = 0;
    while ( lo < hi )
    {
        int mid = (lo+hi)/2, le = 2*node+1, ri = 2*node+2;
        int p = T[ri].minpos, x = T[ri].sum - (p == inf ? 0 : p-mid-1);
        if ( p+x <= b )
        {
            node = ri;
            lo = mid+1;
        }
        else
        {
            node = le;
            hi = mid;
            b -= T[ri].sum;
        }
    }
    return ( a[lo] == 0 && lo == b ? lo : inf );
}

int main()
{
    int m;
    bool valid;
    
    while ( cin >> n >> m )
    {
        valid = true;
        memset(sol, 0, sizeof sol);
        memset(a, 0, sizeof a), init();
        memset(lastseen, -1, sizeof lastseen);
        // Solution generation
        events.clear();
        forn(q, m)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if ( !valid ) continue;
            
            events.pb( Event(q, q, x, inf) );
            if ( lastseen[x] != -1 && lastseen[x]+1 <= q-1 )
            {
                events.pb( Event(lastseen[x]+1, q-1, inf, y-1) );
            }
            if ( lastseen[x] == -1 )
            {
                int p = find(y-1);
                if ( p == inf ) valid = false;
                else            update(p, 1), sol[p] = x;
            }
            lastseen[x] = q;
        }
        // Solution verification
        if ( valid && (int)events.size() > m )
        {
            memset(a, 0, sizeof a), init();
            memset(lastseen, -1, sizeof lastseen);
            sort(all(events));
            forn(i,events.size())
            {
                if ( events[i].val == inf )
                {
                    TreeNode r = query(events[i].start, events[i].end);
                    if ( r.sum != events[i].expected ) { valid = false; break; }
                }
                else
                {
                    int x = events[i].val;
                    if ( lastseen[x] != -1 ) update(lastseen[x], 0);
                    lastseen[x] = events[i].start;
                    update(events[i].start, 1);
                }
            }
        }
        // Solution output
        if ( valid )
        {
            int x = 1;
            forn(i,n) 
            {
                if ( sol[i] ) printf("%d ", sol[i]);
                else
                {
                    while ( lastseen[x] != -1 ) ++x;
                    printf("%d ", x++);
                }
            }
            puts("");
        } else puts("-1");
    }
	
    return 0;
}
