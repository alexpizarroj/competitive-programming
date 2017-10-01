#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

typedef pair<int, int> ii;
int dp[10005], L[3], C[3], s, t;

int main()
{
    int n, station, dist;
    deque<ii> f[3];
    
    while ( cin >> L[0] >> L[1] >> L[2]
            >> C[0] >> C[1] >> C[2], cin )
    {
        cin >> n >> s >> t;
        if ( s > t ) swap(s, t);
        dist = 0;
        for(int i = 2; i <= s; i++) cin >> dist;
        for(int i = 0; i < 3; i++)
        {
            f[i].clear();
            f[i].push_front( ii(dist,s) );
        }
        
        dp[s] = 0;
        for(station = s+1; station <= n; station++)
        {
            cin >> dist;
            if ( station > t ) continue;
            
            dp[station] = 1e9 + 7;
            for(int i = 0; i < 3; i++)
            {
                while ( f[i].size() > 0 &&
                    dist-f[i].front().first > L[i] ) 
                {
                    f[i].pop_front();
                }
                if ( f[i].size() > 0 )
                {
                    int fartest = f[i].front().second;
                    dp[station] = min(dp[station], dp[fartest] + C[i]);
                }
                f[i].push_back( ii(dist,station) );
            }
        }
        
        cout << dp[t] << endl;
    }
    
    return 0;
}