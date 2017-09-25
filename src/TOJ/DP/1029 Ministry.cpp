#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9+7;
vector<vii> g;
int m, n, fee[105][505], dist[50010];
bitset<50010> visited;
vi parent, ans;

inline int id(int floor, int room) { return ((floor-1)*n + room); }

inline int id_to_room(int id) { return (id%n == 0 ? n : id%n); }

void backtrack(int u)
{
    if ( parent[u] != -1 ) backtrack(parent[u]);
    if ( 1 <= u && u <= m*n ) ans.push_back(id_to_room(u));
}

int main()
{
    priority_queue< ii, vector<ii>, greater<ii> > q;
    
    while ( ~scanf("%d %d", &m, &n) )
    {
        for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++)
        {
            scanf("%d", &fee[i][j]);
        }
        
        // Graph modeling
        g.assign(m*n+2, vii());
        for(int i = 1; i <= n; i++)
        {
            g[0].push_back( ii(id(1,i), fee[1][i]) ); // from: start -> 1st floor
            g[id(m,i)].push_back( ii(m*n+1, 0) );     // from: m-th floor -> end
        }
        for(int i = 2; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // jumping for j-th room on the floor below
                g[id(i-1,j)].push_back( ii(id(i,j), fee[i][j]) );
                // left jumping
                if ( j > 1 )
                {
                    g[id(i,j)].push_back( ii(id(i,j-1), fee[i][j-1]) );
                }
                // right jumping
                if ( j < n )
                {
                    g[id(i,j)].push_back( ii(id(i,j+1), fee[i][j+1]) );
                }
            }
        }
        
        // Dijkstra
        for(int top = m*n+1, i = 0; i <= top; i++) dist[i] = INF;
        visited.reset(); dist[0] = 0;
        parent.assign(m*n+1, -1);
        q.push( ii(dist[0], 0) );
        while ( !q.empty() )
        {
            int u = q.top().second; q.pop();
            if ( visited[u] ) continue;
            visited[u] = true;
            //printf("On %d with cost %d\n", u, dist[u]);
            
            for(int i = 0; i < (int)g[u].size(); i++)
            {
                int v = g[u][i].first, cost = g[u][i].second;
                if ( !visited[v] )
                {
                    if( dist[u] + cost < dist[v] )
                    {
                        parent[v] = u;
                        dist[v] = dist[u] + cost;
                        q.push( ii(dist[v], v) );
                        //printf("\tNew dist to %d: %d\n", v, dist[v]);
                    }
                }
            }
        }
        
        // Backtrack
        ans.clear();
        backtrack(m*n+1);
        for(int i = 0; i < (int)ans.size(); i++)
        {
            if ( i > 0 ) printf(" ");
            printf("%d", ans[i]);
        }
        puts("");
    }
    
    return 0;
}