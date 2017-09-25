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
#define PB 				        push_back
#define F                       first
#define S                       second
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define dall(a)		 	        (a).begin(), (a).end()
#define dinit(a) 		        memset(a, -1, sizeof(a))
#define dclr(a)         	 	memset(a, 0, sizeof(a))
#define dbet(lb,v,ub)			(lb <= v && v <= ub)
using namespace std; const int INF = int(1E9+7);
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> ii; typedef vector<int> vi;

int mp[300], mp_size, wakers[30], dist[30];
bool used[30][30];
vector< vi > g;

inline int getId(int c)
{ if( mp[c] == -1 ) mp[c] = mp_size++; return mp[c]; }

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n, m, x, y, z, years, nWoken;
	char wokenAreas[4], buffer[4];
	queue<int> q;

	while ( scanf("%d %d", &n, &m) != EOF )
	{
        g.assign( n, vi() );
        dinit(mp); mp_size = 0;
        dclr(used); dclr(wakers);

        // Input
        scanf("%s", wokenAreas);
        fup(i,0,m)
        {
            scanf("%s", buffer);
            x = getId(buffer[0]), y = getId(buffer[1]);
            if( !used[x][y] && !used[x][y])
            {
                g[x].PB(y);
                g[y].PB(x);
                used[x][y] = used[y][x] = true;
            }
        }
        x = getId(wokenAreas[0]), y = getId(wokenAreas[1]), z = getId(wokenAreas[2]);

        // Processing
        years = 0, nWoken = 3;
        wakers[x] = wakers[y] = wakers[z] = 3;
        dist[x] = dist[y] = dist[z] = 0;
        q.push(x); q.push(y); q.push(z);

        while ( !q.empty() )
        {
            int v = q.front(); q.pop();
            fup(i,0,g[v].size())
            {
                const int& w = g[v][i];
                wakers[w]++;
                if( wakers[w] == 3 )
                {
                    dist[w] = dist[v] + 1;
                    q.push(w);
                    years = max(years, dist[w]), nWoken++;
                }
            }
        }

        // Output
        if( nWoken == n )
            printf("WAKE UP IN, %d, YEARS\n", years);
        else
            puts("THIS BRAIN NEVER WAKES UP");
	}

    return 0;
}
