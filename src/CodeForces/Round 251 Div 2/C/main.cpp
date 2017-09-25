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

vi even, odd;
int n, m, p;

int main()
{
    int N, K, P;
    while ( cin >> N >> K >> P )
    {
        even.clear(); odd.clear();
        forn(i,N)
        {
            int a;
            scanf("%d", &a);
            if ( a&1 ) odd.pb(a); else even.pb(a);
        }
        n = even.size(), m = odd.size(), p = 0;
        while ( m > K-P && m >= 2 ) m -= 2, p += 2, n += 1;
        if ( m == K-P && n >= P )
        {
            vi buffer;
            int e = 0, o = 0;
            
            puts("YES");
            forn(k,m)
            {
                buffer.clear();
                if ( o == 0 && P == 0 && n > 0 )
                {
                    int sz = n, got = 0;
                    while ( got < sz && e < (int)even.size() )
                    {
                        buffer.pb(even[e]);
                        ++e, ++got;
                    }
                    while ( got < sz && o+1 < (int)odd.size() )
                    {
                        buffer.pb(odd[o]);
                        buffer.pb(odd[o+1]);
                        o += 2, ++got;
                    }
                }
                buffer.pb(odd[o++]);
                
                printf("%d", (int)buffer.size());
                forn(i,buffer.size()) printf(" %d", buffer[i]);
                puts("");
            }
            forn(k,P)
            {
                int sz = ( k == 0 ? 1 + (n-P) : 1), got = 0;
                buffer.clear();
                while ( got < sz && e < (int)even.size() )
                {
                    buffer.pb(even[e]);
                    ++e, ++got;
                }
                while ( got < sz && o+1 < (int)odd.size() )
                {
                    buffer.pb(odd[o]);
                    buffer.pb(odd[o+1]);
                    o += 2, ++got;
                }
                
                printf("%d", (int)buffer.size());
                forn(i,buffer.size()) printf(" %d", buffer[i]);
                puts("");
            }
            continue;
        }
        puts("NO");
    }
    return 0;
}
