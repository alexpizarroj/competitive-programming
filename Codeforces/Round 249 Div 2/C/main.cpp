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

int main()
{
    int n;
    while ( scanf("%d", &n) != EOF )
    {
        vi vec;
        int mx, mn, x, y;
        x = y = mx = mn = 0;
        forn(i,n)
        {
            int value;
            scanf("%d", &value);
            vec.pb(value);
            x += value, y += (i&1 ? -1 : 1)*value;
            mx = max(mx, y), mn = min(mn, y);
        }
        
        int s = 1;
        vector<string> ans(mx-mn, string(x, ' '));
        x = (int)ans.size() - 1 - abs(mn), y = 0;
        forn(i,vec.size())
        {
            forn(j,vec[i])
            {
                ans[x][y] = (s == 1 ? '/' : '\\');
                x += -s*1, y += 1;
            }
            x += s*1, s *= -1;
        }
        
        forn(i,ans.size()) printf("%s\n", ans[i].c_str());
    }
    return 0;
}
