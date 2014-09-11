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
typedef long long       i64;
typedef vector<i64>     vi64;

vector<vi> g;
vi order, visited;
int n, nVisited;

void dfs(int u)
{
    visited[u] = true;
    ++nVisited;
    
    bool found;
    do
    {
        found = false;
        forn(i,g[u].size())
        {
            int v = g[u][i];
            if ( visited[v] ) continue;
            
            // Is this the city we want to go next?
            if ( v == order[nVisited-1] )
            {
                found = true;
                dfs(v);
                break;
            }
        }
    } while ( found );
}

int main()
{
    int tc;
    vector<string> postal;
    
    cin >> tc;
    fore(caso, 1, tc)
    {
        printf("Case #%d: ", caso);
        
        // Input
        int m, startCity;
        string bestzip(5, '9');
        
        cin >> n >> m;
        postal.clear();
        forn(i,n)
        {
            string zip;
            cin >> zip;
            postal.pb(zip);
            if ( bestzip > zip )
            {
                startCity = i;
                bestzip = zip;
            }
        }
        g.assign(n, vi());
        forn(i,m)
        {
            int x, y;
            cin >> x >> y;
            --x, --y;
            g[x].pb(y);
            g[y].pb(x);
        }
        
        // Solution
        string ans(5*n, '9'), cand;
        char buffer[200];
        
        order.clear();
        forn(i,n) if ( i != startCity ) order.pb(i);
        sort(all(order));
        do
        {
            strcpy(buffer, postal[startCity].c_str());
            forn(i,order.size()) strcat(buffer, postal[order[i]].c_str());
            cand = string(buffer, buffer+5*n);
            if ( cand < ans )
            {
                visited.assign(n, false);
                nVisited = 0;
                dfs(startCity);
                if ( nVisited == n )
                {
                    ans = cand;
                }
            }
        }
        while ( next_permutation(all(order)) );
        
        // Output
        cout << ans << endl;
    }
	
    return 0;
}
