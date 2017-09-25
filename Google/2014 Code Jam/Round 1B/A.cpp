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

vii getCharVec(string s)
{
    vii res;
    int freq = 0;
    char cur = s[0];
    
    forn(i,s.size())
    {
        if ( s[i] == cur )
        {
            ++freq;
        }
        else
        {
            res.pb(ii(cur,freq));
            cur = s[i];
            freq = 1;
        }
    }
    res.pb(ii(cur,freq));
    
    return res;
}

int main()
{
    int tc, n;
    vector<vii> lst;
    vi sums;
    string text;
    bool valid;
    
    cin >> tc;
    fore(caso,1,tc)
    {
        printf("Case #%d: ", caso);
        scanf("%d", &n);
        lst.clear();
        forn(i,n)
        {
            cin >> text;
            lst.pb(getCharVec(text));
        }
        
        valid = true;
        fore(i,1,n-1)
        {
            if ( lst[0].size() != lst[i].size() ) { valid = false; break; }
            forn(j,lst[0].size())
            {
                if ( lst[0][j].first != lst[i][j].first ) { valid = false; break; }
            }
        }
        
        if ( valid )
        {
            int m = lst[0].size(), ans = 0;
            forn(i,m)
            {
                vi values;
                forn(j,n) values.pb(lst[j][i].second);
                sort(all(values));
                int mid = values[values.size()/2];
                forn(j,n) ans += abs(mid-lst[j][i].second);
            }
            printf("%d\n", ans);
        }
        else puts("Fegla Won");
    }
	
    return 0;
}
