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

int ccs, cce;
vector<vi> g;
bool visited[10010];

void dfs(int u)
{
	visited[u] = true;
	++ccs, cce += g[u].size();
	forn(i,g[u].size())
	{
		int v = g[u][i];
		if ( !visited[v] )
			dfs(v);
	}
}

int main()
{
    int tc;
	cin >> tc;
	while ( tc-- )
	{
		int n, m;
		scanf("%d %d", &n, &m);
		g.assign(n, vi());
		forn(i,m)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			--x, --y;
			g[x].pb(y);
			g[y].pb(x);
		}
		int ans = 0;
		memset(visited, 0, sizeof visited);
		forn(x,n)
			if ( !visited[x] )
			{
				ccs = cce = 0;
				dfs(x);
				if ( cce/2 == ccs )
					++ans;
			}
		printf("%d\n", ans);
	}
    return 0;
}
