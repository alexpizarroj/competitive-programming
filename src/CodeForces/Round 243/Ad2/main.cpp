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
typedef long long       i64;
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<i64>     vi64;

int main()
{
    int n, s;
    
    while ( cin >> n >> s )
    {
        int sum = 0, mx = -inf;
        forn(i,n) 
        {
            int a;
            cin >> a;
            sum += a;
            mx = max(mx, a);
        }
        puts(sum-mx <= s ? "YES" : "NO");
    }
	
    return 0;
}
