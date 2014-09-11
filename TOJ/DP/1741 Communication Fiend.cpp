#include <cstdio>
#include <vector>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
using namespace std;
typedef long long longint;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const longint INF = 1e10 + 7;

int lic_id(int x) { return ( x == 1 ? 0 : 2*x-3 ); }
int pir_id(int x) { return ( x == 1 ? 0 : 2*x-2 ); }

int main()
{
    int n, m, x, y, downsize;
    vector<longint> dist;
    vector<vii> adj; // per edge: (destination, weight)
    longint ans;
    char s[20];
    
    while ( ~scanf("%d %d", &n, &m) )
    {
        adj.assign(pir_id(n)+1, vii());
        fup(i,0,m)
        {
            scanf("%d %d %d %s", &x, &y, &downsize, s);
            if ( s[0] == 'L' ) // Licensed
            {
                adj[lic_id(x)].push_back(ii(lic_id(y),downsize));
            }
            else if ( s[0] == 'P' ) // Pirated
            {
                adj[lic_id(x)].push_back(ii(pir_id(y),downsize));
                adj[pir_id(x)].push_back(ii(pir_id(y),downsize));
            }
            else // Cracked
            {
                adj[lic_id(x)].push_back(ii(lic_id(y),downsize));
                adj[pir_id(x)].push_back(ii(pir_id(y),downsize));
            }
        }
        dist.assign(pir_id(n)+1, INF), dist[0] = 0;
        fupi(u,0,pir_id(n)) fup(i,0,adj[u].size())
        {
            int v = adj[u][i].first, w = adj[u][i].second;
            dist[v] = min(dist[v], dist[u] + w);
        }
        
        ans = min(dist[lic_id(n)], dist[pir_id(n)]);
        if ( ans == INF ) puts("Offline");
        else printf("Online\n%I64d\n", ans);
    }
	
    return 0;
}
