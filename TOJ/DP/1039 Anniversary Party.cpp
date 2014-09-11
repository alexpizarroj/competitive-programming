#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define SET(a,val) memset((a), val, sizeof (a))
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
using namespace std;

const int cstInvalid = -1, cstMaxNodes = 6010;
const int INVITED = 1, NOT_INVITED = 0;
typedef pair<int, int> ii;

int n, root, dp[cstMaxNodes][2];
int parent[cstMaxNodes], value[cstMaxNodes], children[cstMaxNodes];
int childrenStart[cstMaxNodes], childrenCount[cstMaxNodes];
int level[cstMaxNodes];

int solve()
{
    vector<ii> vec;
    int u, v, s, e;

    fupi(i,1,n) vec.PB( ii(level[i], i) );
    sort(ALL(vec), greater<ii>());

    fup(i,0,n)
    {
        u = vec[i].second;

        if ( childrenCount[u] == 0 )
        {
            dp[u][INVITED] = value[u]; // If invited
            dp[u][NOT_INVITED] = 0; // If not invited
        }
        else
        {
            s = childrenStart[u], e = s + childrenCount[u];
            // If invited:
            dp[u][INVITED] = value[u];
            fup(i,s,e)
            {
                v = children[i];
                dp[u][INVITED] += dp[v][NOT_INVITED];
            }
            // If not invited:
            dp[u][NOT_INVITED] = 0;
            fup(i,s,e)
            {
                v = children[i];
                dp[u][NOT_INVITED] += max( dp[v][INVITED], dp[v][NOT_INVITED] );
            }
        }
    }

    return max( dp[root][INVITED], dp[root][NOT_INVITED] );
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

    int nodeValue, c, p;
    vector<ii> vec;
    queue<int> q;
    int u, v, s, e;

    while ( ~scanf("%d", &n) )
    {
        fupi(i,1,n)
        {
            scanf("%d", &nodeValue);
            parent[i] = i;
            value[i] = nodeValue;
        }

        SET(childrenCount, 0);
        while ( scanf("%d %d", &c, &p), (c || p) )
        {
            parent[c] = p;
            vec.PB( ii(p, c) );
            ++childrenCount[p];
        }
        fupi(i,1,n) if ( parent[i] == i ) { root = i; break; }
        sort(ALL(vec));
        SET(childrenStart, cstInvalid);
        fup(i,0,vec.size())
        {
            p = vec[i].first;
            if ( childrenStart[p] == cstInvalid ) childrenStart[p] = i;
            children[i] = vec[i].second;
        }
        vec.clear();
        
        q.push(root); level[root] = 0;
        while ( !q.empty() )
        {
            u = q.front(); q.pop();
            s = childrenStart[u], e = s + childrenCount[u];
            fup(i,s,e)
            {
                v = children[i];
                level[v] = level[u] + 1;
                q.push(v);
            }
        }

        printf("%d\n", solve() );
    }

    return 0;
}
