#include <iostream>
#include <string>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
using namespace std;

const int INF = int(1e9+7);
bool ispalin[4005][4005];
int dist[4005], p[4005], sol[4005];

int main()
{
    string s;
    int n, m, u;
    
    while ( cin >> s )
    {
        n = s.size();
        fupi(k,1,n) fup(i,0,n-k+1)
        {
            int j = i+k-1;
            ispalin[i][j] = (s[i]==s[j]) && (i+2<=j ? ispalin[i+1][j-1] : true);
        }
        fill(dist, dist+n+1, INF);
        dist[0] = 0, p[0] = 0;
        fup(i,0,n) fup(j,i,n) if ( ispalin[i][j] )
        {
            if ( dist[i]+1 < dist[j+1] )
            {
                dist[j+1] = dist[i]+1;
                p[j+1] = i;
            }
        }
        
        cout << dist[n] << endl;
        u = n, m = 0;
        while ( p[u] != u ) sol[m++] = p[u], u = p[u];
        for(int i = m-1; i >= 0; --i)
        {
            int k = ( i > 0 ? sol[i-1] : n );
            if ( i < m-1 ) cout << " ";
            fup(j,sol[i],k) cout << s[j];
        }
        cout << endl;
    }
	
    return 0;
}
