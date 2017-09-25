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

int main()
{
    int tc, a, b, k;
    
    cin >> tc;
    fore(caso,1,tc)
    {
        printf("Case #%d: ", caso);
        cin >> a >> b >> k;
        int ans = 0;
        forn(i,a) forn(j,b) if ( (i&j) < k ) ++ans;
        printf("%d\n", ans);
    }
	
    return 0;
}
