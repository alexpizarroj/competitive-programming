#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define PB push_back
#define ALL(a) (a).begin(), (a).end()
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
using namespace std;
typedef pair<int,int> ii;

const int MAX = int(3*(1e5));
int n, fq[MAX+5], bit[MAX+5];

int sum(int x)
{
	int result = 0;
	for(int i = x; i >= 0; i = (i & (i+1)) - 1)
		result += bit[i];
	return result;
}

void inc(int x, int delta)
{
	for(int i = x; i < n; i = (i | (i+1)))
		bit[i] += delta;
}

int main()
{
    int p, x, y, maxfq;
    vector<ii> sta;
    long long ans;
    
    while ( scanf("%d %d", &n, &p) != EOF )
    {
        sta.clear();
        memset(fq, 0, sizeof fq);
        memset(bit, 0, sizeof bit);
        fup(i,0,n)
        {
            scanf("%d %d", &x, &y);
            ++fq[x], ++fq[y];
            sta.PB( x <= y ? ii(x,y) : ii(y,x) );
        }
        sort(ALL(sta));
        maxfq = 0;
        fupi(i,1,n) if ( fq[i] > 0 )
        {
            inc(fq[i], 1);
            if ( fq[i] > maxfq ) maxfq = fq[i];
        }
        
        int idx = 0;
        ans = 0;
        fup(cur,1,n)
        {
            if ( fq[cur] > 0 ) inc(fq[cur], -1);
            if ( fq[cur] < p )
            {
                ans += sum(maxfq) - sum(p-fq[cur]-1);
                for(; idx < n && sta[idx].first < cur; ++idx);
                while ( idx < n && sta[idx].first == cur )
                {
                    int a = sta[idx].second, cnt = 0;
                    while ( idx < n && sta[idx].first == cur && 
                        sta[idx].second == a ) ++cnt, ++idx;
                    if ( fq[cur]+fq[a] >= p && fq[cur]+fq[a]-cnt < p ) --ans;
                }
            }
            else ans += n-cur;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
