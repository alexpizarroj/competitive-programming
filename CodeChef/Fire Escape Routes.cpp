#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
using namespace std;

const int M = int(1E9+7);
typedef vector<int> vi;
vi p, sz, rank;
int nSets;

void init(int n)
{
    p.resize(n); fup(i,0,n) p[i] = i;
    sz.assign(n, 1); rank.assign(n, 0);
    nSets = n;
}

int find(int u)
{
    return (u == p[u] ? u : p[u] = find(p[u]));
}

void merge(int u, int v)
{
    u = find(u), v = find(v);
    if ( u == v ) return;

    --nSets;
    if ( rank[u] < rank[v] )
    {
        p[u] = v, sz[v] += sz[u];
    }
    else
    {
        p[v] = u, sz[u] += sz[v];
        if ( rank[u] == rank[v] ) ++rank[u];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
#endif
	int t, n, m, u, v;
	long long ways;

    cin >> t;
	while ( t-- )
	{
	    cin >> n >> m;
	    init(n);
	    fup(i,0,m)
	    {
            cin >> u >> v;
            merge(u-1, v-1);
	    }
	    ways = 1;
	    fup(i,0,n)
	    {
	        if ( p[i] == i ) ways = (ways * sz[i]) % M;
	    }
	    cout << nSets << " " << ways << endl;
	}

    return 0;
}
