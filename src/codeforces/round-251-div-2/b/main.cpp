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
    int n, x;
    while ( cin >> n >> x )
    {
        vi ch;
        forn(i,n)
        {
            int a;
            scanf("%d", &a);
            ch.pb(a);
        }
        sort(all(ch));
        unsigned long long ans = 0;
        forn(i,n)
        {
            ans += (unsigned long long)ch[i] * (unsigned long long)x;
            x = max(1, x-1);
        }
        cout << ans << endl;
    }
    return 0;
}
