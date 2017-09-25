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
    int h, r;
    while ( scanf("%d %d", &h, &r), h || r )
    {
        vi deg(h, 0);
        forn(i,r)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            ++deg[a-1], ++deg[b-1];
        }
        sort(all(deg), greater<int>());
        
        int m, sum, indset;
        for(m = 0; m < h && deg[m] >= m; ++m);
        sum = accumulate(deg.begin(), deg.begin()+m, 0);
        indset = accumulate(deg.begin()+m, deg.end(), 0);
        puts(m*(m-1) + indset == sum ? "Y" : "N");
    }
    return 0;
}