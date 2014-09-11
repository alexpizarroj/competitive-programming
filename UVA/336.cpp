#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <fstream>
#define PB 				        push_back
#define MP 				        make_pair
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fdo(i,a,b) 		        for(int i = (a); (i) > int(b); i--)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define fdoi(i,a,b) 		    for(int i = (a); (i) >= int(b); i--)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define all(a)		 	        (a).begin(), (a).end()
#define set(a,v) 		        memset(a, v, sizeof(a))
#define clr(a)         	 	    memset(a, 0, sizeof(a))
#define least_first_heap(T)     priority_queue<T, deque<T>, std::greater<T> >
using namespace std;

typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii;
template<class T> bool inline between(const T& lb, const T& v, const T& ub) { return lb<=v && v<=ub; }
const int INF = 1E9+7;

#define MAX_NODES 30
vector<int> edge[MAX_NODES];
map<int,int> id;
int nNodes;

int count_unreachable(int start, int ttl) /* bfs */
{
    queue<pii> q;
    int nNodes = id.size();
    vector<bool> visited(nNodes, false);

    q.push( make_pair(start,0) );
    visited[start] = true;
    while( !q.empty() )
    {
        pii top = q.front(); q.pop();
        if( top.second < ttl )
        {
            // Loop through all the neighbors
            fup(i,0, edge[top.first].size() )
            {
                int node = edge[top.first][i];
                if( !visited[node] )
                {
                    visited[node] = true;
                    q.push( make_pair(node, top.second+1) );
                }
            }
        }
    }

    return count(visited.begin(), visited.end(), 0);
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	#endif

	int nc, x, y;
	int start, ttl, tc=1;

	while( scanf("%d", &nc), nc > 0 )
	{
	    id.clear();
	    fup(i,0,MAX_NODES) edge[i].clear();

        // Graph reading
        int cnt = 0;
	    fup(i,0,nc)
	    {
            scanf("%d %d", &x, &y);
            if( id.count(x) == 0 )
            {
                id[x] = cnt++;
            }
            if( id.count(y) == 0 )
            {
                id[y] = cnt++;
            }
            edge[ id[x] ].push_back( id[y] );
            edge[ id[y] ].push_back( id[x] );
	    }

        // Queries processing
	    while( scanf("%d %d", &start, &ttl), start || ttl )
	    {
	        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
                tc++, count_unreachable(id[start], ttl), start, ttl);
	    }
	}

    fclose(stdout);
    return 0;
}
