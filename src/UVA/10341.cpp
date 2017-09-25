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

int p, q, r, s, t, u;

double f(double x)
{
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double solve()
{
	double lo = 0, hi = 1;
	fore(it,1,50)
	{
		double mid = (lo+hi)/2, r = f(mid);
		if ( r < 0 )
			hi = mid;
		else if ( r > 0 )
			lo = mid;
	}
	return lo;
}

int main()
{
    while ( scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF )
	{
		if ( f(1) <= 0 && 0 <= f(0) )
			printf("%.4lf\n", solve());
		else
			puts("No solution");
	}
    return 0;
}
