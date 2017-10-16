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
typedef unsigned long long ui64;

ui64 gcd(ui64 a, ui64 b)
{
	ui64 c;
	while ( b != 0 )
		c = a%b, a = b, b = c;
	return a;
}

ui64 mod(int x1, int y1, int x2, int y2)
{
	int xv = x1 - x2, yv = y1 - y2;
	return (xv*xv) + (yv*yv);
}

int x[3], y[3];
void getRF(ui64 &nu, ui64 &de)
{
	nu = mod(x[0], y[0], x[1], y[1]);
	nu *= mod(x[0], y[0], x[2], y[2]);
	nu *= mod(x[2], y[2], x[1], y[1]);
	de = x[0]*y[1] + x[1]*y[2] + x[2]*y[0];
	de -= x[0]*y[2] + x[1]*y[0] + x[2]*y[1];
	de = 4 * de * de;
	ui64 g = gcd(nu, de);
	nu /= g, de /= g;
}

int main()
{
    int n;
	while ( cin >> n )
	{
		ui64 nu, de;
		map< pair<ui64,ui64> , int > freq;
		forn(i,n)
		{
			forn(k,3) scanf("%d %d", x+k, y+k);
			getRF(nu, de);
			++freq[ make_pair(nu,de) ];
		}
		int ans = 1;
		foreach(el, freq)
			ans = max(ans, el->second);
		printf("%d\n", ans);
	}
    return 0;
}
