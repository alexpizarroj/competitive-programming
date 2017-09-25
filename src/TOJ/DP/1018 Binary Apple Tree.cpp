#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cassert>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int INVALID = 1e7;
vector<vii> g;
vector<vi> dp;
vi parent, desc;

void dfs(int u)
{
    int childCount = 0;
    
    for(int i = 0; i < (int)g[u].size(); i++)
    {
        int v = g[u][i].first;
        if ( parent[v] == -1 )
        {
            parent[v] = u;
            dfs(v);
            desc[u] += desc[v] + 1;
            childCount++;
        }
    }
    assert(childCount <= 2);
    
    if ( childCount > 0 )
    {
        // Child Recovery
        int child[2] = {0}, childCost[2], idx = 0;
        for(int i = 0; i < (int)g[u].size(); i++)
        {
            int v = g[u][i].first;
            if ( parent[v] == u ) 
            {
                child[idx] = v;
                childCost[idx++] = g[u][i].second;
            }
        }
        
        // DP UPDATE
        switch( childCount )
        {
            case 1:
            {
                int v = child[0];
                
                for(int i = 0; i < (int)dp[u].size(); i++) dp[u][i] = dp[v][i];
                dp[u][desc[v]+1] = dp[v][desc[v]] + childCost[0];
                
                break;
            }
            case 2:
            {
                int a = child[0], b = child[1];
                
                dp[a][desc[a]+1] = dp[a][desc[a]] + childCost[0];
                dp[b][desc[b]+1] = dp[b][desc[b]] + childCost[1];
                for(int i = 0; i < (int)dp[a].size(); i++)
                {
                    for(int j = 0; j < (int)dp[b].size(); j++)
                    {
                        if ( i+j >= (int)dp[u].size() ) continue;
                        dp[u][i+j] = min(dp[u][i+j], dp[a][i] + dp[b][j]);
                    }
                }
                dp[a][desc[a]+1] = dp[b][desc[b]+1] = INVALID;
                
                break;
            }
        }
    }
}

int main()
{
    int n, q, u, v, cost, totalApples;
    vi emptyTable(105, INVALID);
    
    emptyTable[0] = 0;
    while ( ~scanf("%d %d", &n, &q) )
    {
        g.assign(n+1, vii());
        dp.assign(n+1, emptyTable);
        totalApples = 0;
        for(int i = 0; i < n-1; i++)
        {
            scanf("%d %d %d", &u, &v, &cost);
            g[u].push_back( ii(v, cost) );
            g[v].push_back( ii(u, cost) );
            totalApples += cost;
        }
        
        // O( N * Q^2 )
        parent.assign(n+1, -1);
        desc.assign(n+1, 0);
        parent[1] = 0; dfs(1);
        
        printf("%d\n", totalApples - dp[1][n-1-q]);
    }

    return 0;
}