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
    int n;
    while ( scanf("%d", &n), n )
    {
        int sum = 0, ans = 0;
        forn(i,n)
        {
            int value;
            scanf("%d", &value);
            sum += value;
            if ( sum < 0 ) sum = 0;
            ans = max(ans, sum);
        }
        if ( ans > 0 )  printf("The maximum winning streak is %d.\n", ans);
        else            puts("Losing streak.");
    }
    
    return 0;
}