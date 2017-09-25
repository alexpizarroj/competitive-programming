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

inline int low(int n, int m, int k)
{
	return max(k-m+1,0);
}

inline int high(int n, int m, int k)
{
	return min(n-1,k);
}

long long solve(int n, int m, int k)
{
	long long ans = -1;
	if ( k <= (n+m-2) )
	{
		int x;
		long long lo ,hi;
		x = low(n, m, k);
		lo = (long long)(n/(x+1)) * (m/(k-x+1));
		x = high(n, m, k);
		hi = (long long)(n/(x+1)) * (m/(k-x+1));
		ans = max(lo, hi);
	}
	return ans;
}

int main()
{
    int n, m, k;
	while ( cin >> n >> m >> k )
		cout << solve(n, m, k) << endl;
    return 0;
}
