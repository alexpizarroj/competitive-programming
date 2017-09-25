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
	int N, cap;
    while ( cin >> N >> cap )
    {
        vi vec(N);
        forn(i, N) scanf("%d", &vec[i]);
        sort(all(vec));
        reverse(all(vec));
        int cur = 0, ans = 0;
        while ( cur < N )
        {
            int first = min(cur + cap - 1, N - 1);
            int lastFloor = vec[cur];
            ans += (lastFloor-1) * 2;
            cur = first + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
