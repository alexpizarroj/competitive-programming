#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
using namespace std;
#define PB push_back

typedef vector<int> vi;
const int INF = 1000000;

// (0) source, (1-26) apps, (27-36) pcs, (37) sink
int res[40][40];
vector<vi> adjList;
int source, sink;

int find_path()
{
    queue<int> q;
    bitset<38> visited;
    vi from(38, -1);
    bool path_found;
    int u, v, f;
    
    visited.reset();
    q.push(source); visited[source] = true;
    path_found = false;
    while ( !path_found && !q.empty() )
    {
        u = q.front(); q.pop();
        for(int i = 0; i < (int)adjList[u].size(); ++i)
        {
            v = adjList[u][i];
            if ( res[u][v] > 0 && !visited[v] )
            {
                from[v] = u;
                if ( v == sink ) { path_found = true; break; }
                q.push(v); visited[v] = true;
            }
        }
    }
    
    f = INF;
    if ( path_found )
    {
        for(v = sink; from[v] > -1; v = from[v])
            f = min(res[from[v]][v], f);
        for(v = sink; from[v] > -1; v = from[v])
            u = from[v], res[u][v] -= f, res[v][u] += f;
    }
    
    return (f == INF ? 0 : f);
}

int maxflow()
{
    int mf = 0, d;
    while ( d = find_path() ) mf += d;
    return mf;
}

inline void add_edge(int u, int v, int cap)
{ adjList[u].PB(v), adjList[v].PB(u), res[u][v] = cap; }

inline int get_app_id(char c) { return c-'A'+1; }

inline int get_pc_id(char pcIdx) { return pcIdx+27; }

int main()
{
    char buffer[50];
    int nJobs, app, appfreq, pc, nApps;
    
    source = 0, sink = 37;
    while ( true )
    {
        adjList.assign(38, vi());
        memset(res, 0, sizeof res);
        nJobs = nApps = 0;
        
        while ( gets(buffer) != NULL && strlen(buffer) != 0 )
        {
            app = get_app_id(buffer[0]);
            appfreq = buffer[1]-'0';
            add_edge(source, app, appfreq);
            
            for(int i = 3; buffer[i] != ';'; ++i)
            {
                pc = get_pc_id(buffer[i]-'0');
                add_edge(app, pc, INF);
            }
            
            ++nJobs;
            nApps += appfreq;
        }
        if ( nJobs == 0 ) break;
        
        for(int u = get_pc_id(0), hi = get_pc_id(9); u <= hi; ++u)
            add_edge(u, sink, 1);
        
        if ( maxflow() == nApps )
        {
            strcpy(buffer, string(10, '_').c_str());
            for(int i = 0; i <= 9; ++i)
            {
                pc = get_pc_id(i);
                for(int j = 0; j < (int)adjList[pc].size(); ++j)
                {
                    app = adjList[pc][j];
                    if ( app == sink ) continue;
                    if ( res[pc][app] == 1 )  buffer[i] = app-1+'A';
                }
            }
            puts(buffer);
        }
        else
        {
            puts("!");
        }
    }

    return 0;
}