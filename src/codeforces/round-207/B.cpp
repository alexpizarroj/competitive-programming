#include <cstdio>
#include <cstring>
#include <vector>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
using namespace std;

#define UNSET -1
#define WHITE 0
#define BLUE 1
#define RED 2
typedef pair<int,int> AdjPair;
typedef vector<AdjPair> vap;
vector<int> color;
vector<vap> adjList;

int main()
{
    int n, m, triple[3];
    int adj[3][2] = { {BLUE, RED}, {WHITE, RED}, {WHITE, BLUE} };
    
    while ( ~scanf("%d%d", &n, &m) )
    {
        color.assign(n + 1, UNSET);
        while ( m-- )
        {
            scanf("%d%d%d", triple, triple+1, triple+2);
            // try to set triple if at least one is already given
            fup(k,0,3) if ( color[ triple[k] ] != UNSET )
            {
                int cnt = 0;
                fup(j,0,3)
                {
                    if ( j == k ) continue;
                    color[ triple[j] ] = adj[ color[triple[k]] ][cnt++];
                }
                break;
            }
            // if none was set:
            if ( color[ triple[0] ] == UNSET )
            {
                fup(k,0,3) color[ triple[k] ] = k;
            }
        }
        fupi(i,1,n) printf("%d ", color[i]+1);
        puts("");
    }
    
    return 0;
}
