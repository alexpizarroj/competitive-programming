#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

const int maxn = (1e5)+7;
int n, a[maxn];
vector<int> sorted_pos;

struct TreeNode
{
    int maxval, maxpos;
     
    void update(int i)
    {
        this->maxpos = i;
        this->maxval = a[i];
    }
     
    void update(const TreeNode &le, const TreeNode &ri)
    {
        const TreeNode &best = ( le.maxval > ri.maxval ? le : ri );
        this->maxval = best.maxval, this->maxpos = best.maxpos;
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
    auto firstArgSearch = [] (pair<long long, int> a, pair<long long, int> b) {
        return (a.first < b.first);
    };
    int d;
    while ( cin >> n >> d )
    {
        // Input reading + Sorting by height
        vector<long long> h;
        vector< pair<long long,int> > h_sorted;
        h.reserve(n);
        h_sorted.reserve(n);
        sorted_pos.resize(n);
        for(int i = 0; i < n; i++)
        {
            long long value;
            scanf("%lld", &value);
            h.push_back(value);
            h_sorted.push_back(make_pair(value, i));
        }
        sort(h_sorted.begin(), h_sorted.end());
        for(int i = 0; i < n; i++)
            sorted_pos[h_sorted[i].second] = i;
        // Segment Tree initialization
        memset(a, 0, sizeof a);
        init();
        // DP solution
        vector<int> best(n), best_prev(n);
        int ans = 1, ans_pos = 0;
        best[0] = 1;
        best_prev[0] = -1;
        update(sorted_pos[0], best[0]);
        for(int i = 1; i < n; i++)
        {
            // Last element of the list of lower values (low_pos)
            long long low = h[i] - d;
            int low_pos = distance(h_sorted.begin(), 
                upper_bound(h_sorted.begin(), h_sorted.end(),
                    make_pair(low, 0), firstArgSearch
                )
            );
            low_pos = ( low_pos > 0 ? low_pos-1 : n );
            // First element of the list of upper values (hi_pos)
            long long hi = h[i] + d;
            int hi_pos = distance(h_sorted.begin(), 
                lower_bound(h_sorted.begin(), h_sorted.end(), 
                    make_pair(hi, 0), firstArgSearch
                )
            );
            // Best match recovery
            int match = 0, prev = -1;
            if ( low_pos != n )
            {
                TreeNode q = query(0, low_pos);
                if ( q.maxval > match )
                    match = q.maxval, prev = q.maxpos;
            }
            if ( hi_pos != n )
            {
                TreeNode q = query(hi_pos, n-1);
                if ( q.maxval > match )
                    match = q.maxval, prev = q.maxpos;
            }
            best[i] = match + 1;
            best_prev[i] = ( prev != -1 ? h_sorted[prev].second : -1 );
            // Segment Tree Update + Answer Update
            update(sorted_pos[i], best[i]);
            if ( best[i] > ans )
            {
                ans = best[i];
                ans_pos = i;
            }
        }
        // Output
        vector<int> out;
        do
        {
            out.push_back(ans_pos + 1);
            ans_pos = best_prev[ans_pos];
        }
        while ( ans_pos != -1 );
        reverse(out.begin(), out.end());
        printf("%d\n", ans);
        for(auto x : out) printf("%d ", x);
        puts("");
    }
}