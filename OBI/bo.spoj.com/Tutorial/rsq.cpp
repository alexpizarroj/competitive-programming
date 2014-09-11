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

int n;
i64 t[500010], v[500010];

i64 sum(int x)
{
	i64 result = 0;
	for(int i = x; i >= 0; i = (i & (i+1)) - 1)
		result += t[i];
	return result;
}

void inc(int x, i64 delta)
{
    v[x] += delta;
	for(int i = x; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int main()
{
	scanf("%d", &n);
	++n, v[0] = 0;
	fore(i,1,n-1)
	{
		i64 x;
		scanf("%lld", &x);
		inc(i, x);
	}
	
	char oper[10];
	int op1, op2;
	while ( scanf("%s %d %d", oper, &op1, &op2) != EOF )
		if ( oper[1] == 'e' )
			inc(op1, (i64)op2 - v[op1]);
		else
			printf("%lld\n", sum(op2) - sum(op1-1));
    return 0;
}
