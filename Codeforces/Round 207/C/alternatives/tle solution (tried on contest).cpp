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
#define MSB(n) ( n <= 0 ? 0 : int(floor(log(n)/log(2))) )
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;

#define showrange(it) printf("[%d-%d, time=%d, label=%d]\n", it->l, it->r, it->t, it->label)
#define showset(st) foreach(it, st) showrange(it)

struct Range
{
    Range(int _l, int _r, int _t, int _label) : l(_l), r(_r), t(_t), label(_label) { }
    int l, r, t, label;
};

bool operator<(const Range& lhs, const Range& rhs)
{
    if ( lhs.l != rhs.l ) return lhs.l < rhs.l;
    else if ( lhs.t != rhs.t ) return lhs.t < rhs.t;
    return lhs.r < rhs.r;
}

pair<int,int> rangeIntersection(const Range &a, const Range &b)
{
    if ( a.r < b.l || a.l > b.r ) return make_pair(0, 0);
    return make_pair( max(a.l, b.l), min(a.r, b.r) );
}

int main()
{
	typedef set<Range>::iterator RangePtr;
    
    vector<Range> data;
    vector<int> result;
    int n, m;
    int l, r, x;
    
    while ( scanf("%d %d", &n, &m) != EOF )
    {
        // Input
        data.clear();
        fupi(t,1,m)
        {
            scanf("%d %d %d", &l, &r, &x);
            if ( l < x ) data.PB( Range(l, x-1, t, x) ); 
            if ( x < r ) data.PB( Range(x+1, r, t, x) );
        }
        
        // Processing
        set<Range> st( ALL(data) );
        RangePtr cur = st.begin(), next = cur; ++next;
        pair<int,int> inter;
        while ( next != st.end() )
        {
            inter = rangeIntersection(*cur, *next);
            if ( inter.first == 0 )
            {
                cur = next; ++next;
            }
            else
            {
                if ( cur->t > next->t ) swap(cur, next);
                
                Range tmp(*next); st.erase(next);
                if ( inter.first == tmp.l )
                {
                    Range nr(inter.second+1, tmp.r, tmp.t, tmp.label);
                    if ( nr.l <= nr.r ) st.insert( nr );
                }
                else if ( inter.second == tmp.r )
                {
                    Range nr(tmp.l, inter.first-1, tmp.t, tmp.label);
                    if ( nr.l <= nr.r ) st.insert( nr );
                }
                else
                {
                    Range nr(inter.second+1, tmp.r, tmp.t, tmp.label);
                    if ( nr.l <= nr.r ) st.insert( nr );
                    Range nr2(tmp.l, inter.first-1, tmp.t, tmp.label);
                    if ( nr2.l <= nr2.r ) st.insert( nr2 );
                }
                
                next = cur; ++next;
            }
        }
        result.assign(n+1, 0);
        foreach(it, st) fupi(i, it->l, it->r) result[i] = it->label;
        
        // Output
        printf("%d", result[1]);
        for(int i = 2; i <= n; ++i) printf(" %d", result[i]);
        puts("");
    }
    
    return 0;
}