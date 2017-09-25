#include <cstdio>
#include <vector>
#include <algorithm>
#define PB push_back
using namespace std;

struct Interval
{
    int l, r, l1, r1;
    bool operator<(const Interval& rhs) const
    {
        if ( this->l != rhs.l ) return this->l < rhs.l;
        return this->r > rhs.r;
    }
} seg[100005];

int main()
{
    int n, m, r, cur, bestseg;
    vector<Interval> ans;
    
    while ( ~scanf("%d", &m) )
    {
        n = 0;
        while ( scanf("%d %d", &seg[n].l1, &seg[n].r1), seg[n].l1 || seg[n].r1 )
        {
            seg[n].l = max(0, seg[n].l1);
            seg[n].r = min(m, seg[n].r1);
            if ( seg[n].l < seg[n].r ) ++n;
        }
        
        sort(seg, seg+n), r = 0;
        if ( seg[0].l == 0 )
        {
            ans.clear(), ans.PB(seg[0]);
            r = seg[0].r, cur = 1;
            while ( r < m )
            {
                bestseg = -1;
                for(; cur < n && seg[cur].l <= r; ++cur)
                {
                    if ( seg[cur].r > (bestseg == -1 ? r : seg[bestseg].r) )
                    {
                        bestseg = cur;
                    }
                }
                if ( bestseg == -1 ) break;
                
                ans.PB(seg[bestseg]), r = seg[bestseg].r;
            }
        }
        
        if ( r < m )
            puts("No solution");
        else
        {
            printf("%d\n", (int)ans.size());
            for(int i=0; i<(int)ans.size(); ++i)
            {
                printf("%d %d\n", ans[i].l1, ans[i].r1);
            }
        }
    }
	
    return 0;
}
