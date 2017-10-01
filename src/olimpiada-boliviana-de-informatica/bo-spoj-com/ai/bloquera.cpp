#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define PB push_back
typedef vector<int> vi;
typedef pair<int,int> ii;

const int UNVISITED = -1;
vector<vi> adjList;
vector<ii> bridges;
vi dfs_num, dfs_parent, dfs_low;
int dfsCounter;

void dfs(int u)
{
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    for(int i = 0; i < (int)adjList[u].size(); i++)
    {
        int v = adjList[u][i];
        if ( dfs_num[v] == UNVISITED )
        {
            dfs_parent[v] = u;
            dfs(v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            
            if ( dfs_low[v] > dfs_num[u] )
            {
                ii t(u, v);
                if ( t.second < t.first ) swap(t.first, t.second);
                bridges.PB(t);
            }
        }
        else if ( v != dfs_parent[u] )
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
}

int main()
{
    int n, m, nc, u, v;
    int nCase = 1;
    
    scanf("%d", &nc);
    while ( nc-- )
    {
        scanf("%d %d", &n, &m);
        adjList.assign(n+1, vi());
        while ( m-- )
        {
            scanf("%d %d", &u, &v);
            adjList[u].PB(v);
            adjList[v].PB(u);
        }
        
        dfs_num.assign(n+1, UNVISITED);
        dfs_parent.assign(n+1, -1);
        dfs_low.assign(n+1, -1);
        dfsCounter = 0; bridges.clear();
        for(int i = 1; i <= n; i++)
            if ( dfs_num[i]  == UNVISITED ) dfs(i);
        
        printf("Caso #%d\n", nCase++);
        if ( bridges.size() > 0 )
        {
            sort(bridges.begin(), bridges.end());
            printf("%d\n", bridges.size());
            for(int i  = 0; i < (int)bridges.size(); i++)
                printf("%d %d\n", bridges[i].first, bridges[i].second);
        }
        else puts("Sin bloqueos");
    }

    return 0;
}