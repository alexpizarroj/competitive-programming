#include <cstdio>
#include <cstring>
#include <algorithm>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
using namespace std;

struct Segment
{
    int left, right, length, id;
    bool isInsideOf(const Segment &p)
    {
        return ( p.left < left && right < p.right );
    }
    bool operator<(const Segment &rhs) const
    {
        return this->length < rhs.length;
    }
};

int main()
{
    int n, dp[505], next[505], sol[505], ans, ans_idx;
    Segment seg[505];
    
    while ( ~scanf("%d", &n) ) 
    {
        fup(i,0,n) 
        {
            scanf("%d %d", &seg[i].left, &seg[i].right);
            seg[i].length = seg[i].right - seg[i].left + 1;
            seg[i].id = i+1;
        }
        
        sort(seg, seg+n);
        memset(dp, -1, sizeof dp);
        memset(next, -1, sizeof dp);
        ans = 0;
        fup(i,0,n)
        {
            dp[i] = 1;
            fup(j,0,n) if ( seg[j].isInsideOf(seg[i]) )
            {
                if ( dp[j]+1 > dp[i] )
                {
                    dp[i] = dp[j] + 1;
                    next[i] = j;
                }
            }
            if ( dp[i] > ans )
            {
                ans_idx = i;
                ans = dp[i];
            }
        }
        
        printf("%d\n", ans);
        n = 0;
        while ( ans_idx > -1 )
        {
            sol[n++] = seg[ans_idx].id;
            ans_idx = next[ans_idx];
        }
        for(int i = n-1; i >= 0; --i)
        {
            if ( i < n-1 ) printf(" ");
            printf("%d", sol[i]);
        }
        puts("");
    }
	
    return 0;
}
