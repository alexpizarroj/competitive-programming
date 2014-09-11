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
using namespace std;

const int ALPHA_SZ = 'Z'-'A'+1, MAX_CITIES = 700;
int adj[MAX_CITIES][MAX_CITIES];
int degree[MAX_CITIES], from[MAX_CITIES];
bool visited[MAX_CITIES];
char ct1[5], ct2[5];

inline int city_id(const char *c)
{ return (c[0]-'A')*ALPHA_SZ + (c[1]-'A'); }

inline void id_city(int id, char *c)
{
    int ri = id%ALPHA_SZ, le = (id - ri)/ALPHA_SZ;
    c[0] = le+'A', c[1] = ri+'A', c[2] = 0;
}

void print_path(int u, int v)
{
    if ( from[u] > -1 ) print_path(from[u], u);
    id_city(u, ct1), id_city(v, ct2);
    printf("%s %s\n", ct1, ct2);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, u, v;
	int source, dest;
	bool blank = false;

	while ( ~scanf("%d", &n) )
	{
	    memset(degree, 0, sizeof degree);
	    while ( n-- )
	    {
	        scanf("%s %s", ct1, ct2);
            u = city_id(ct1), v = city_id(ct2);
            adj[u][ degree[u]++ ] = v;
            adj[v][ degree[v]++ ] = u;
	    }
	    scanf("%s %s", ct1, ct2);
	    source = city_id(ct1); dest = city_id(ct2);

        queue<int> q;
        memset(visited, 0, sizeof visited);
        memset(from, -1, sizeof from);
        q.push(source); visited[source] = true;
        while ( !visited[dest] && !q.empty() )
        {
            u = q.front(); q.pop();
            for(int i = 0; i < degree[u]; ++i)
            {
                v = adj[u][i];
                if ( !visited[v] )
                {
                    from[v] = u;
                    q.push(v); visited[v] = true;
                    if ( v == dest ) break;
                }
            }
        }

        if ( blank )  puts("");
        if ( visited[dest] ) print_path(from[dest], dest);
        else                 puts("No route");
        blank = true;
	}

    return 0;
}
