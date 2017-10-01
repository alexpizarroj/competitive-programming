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
typedef vector<ii>      vii;
typedef long long       i64;
typedef vector<i64>     vi64;

int a[450][450], dp[450][450], n, m;

bool check(int x, int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

int get(int x1, int y1, int x2, int y2)
{
    if ( x1 == x2 )
    {
        if ( y1 > y2 ) swap(y1, y2);
        return dp[x2][y2] - dp[x2-1][y2] - dp[x1][y1-1] + dp[x1-1][y1-1];
    }
    else if ( y1 == y2 )
    {
        if ( x1 > x2 ) swap(x1, x2);
        return dp[x2][y2] - dp[x2][y2-1] - dp[x1-1][y1] + dp[x1-1][y1-1];
    }
    assert(false);
    return 0;
}

int main()
{
    char row[500];
    const int var[4][4] = {
        {-1, -1, -1, +1},
        {+1, -1, +1, +1},
        {-1, -1, +1, -1},
        {-1, +1, +1, +1}
    };
    while ( scanf("%d %d", &n, &m) != EOF )
    {
        memset(a, 0, sizeof a);
        memset(dp, 0, sizeof dp);
        fore(i,1,n)
        {
            scanf("%s", row);
            fore(j,1,m)
            {
                a[i][j] = row[j-1]-'0';
                dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + a[i][j];
            }
        }
        
        i64 ans = 0;
        // Triangle from point right-diagonal
        fore(i,1,n) fore(j,1,m) if ( a[i][j] == 0 )
        {
            int x = i+1, y = j+1;
            while ( check(x,y) )
            {
                if ( a[x][y] ) break;
                if ( get(i,j,i,y) == 0 && get(i,y,x,y) == 0 ) ++ans;
                if ( get(i,j,x,j) == 0 && get(x,j,x,y) == 0 ) ++ans;
                x += 1, y += 1;
            }
        }
        // Triangle from point left-diagonal
        fore(i,1,n) fore(j,1,m) if ( a[i][j] == 0 )
        {
            int x = i+1, y = j-1;
            while ( check(x,y) )
            {
                if ( a[x][y] ) break;
                if ( get(i,j,i,y) == 0 && get(i,y,x,y) == 0 ) ++ans;
                if ( get(i,j,x,j) == 0 && get(x,j,x,y) == 0 ) ++ans;
                x += 1, y += -1;
            }
        }
        // Triangle from point to matrix sides
        forn(r,4) fore(i,1,n) fore(j,1,m) if ( a[i][j] == 0 )
        {
            int x1=i+var[r][0], y1=j+var[r][1];
            int x2=i+var[r][2], y2=j+var[r][3];
            while ( check(x1,y1) && check(x2,y2) )
            {
                if ( a[x1][y1] || a[x2][y2] ) break;
                if ( get(x1,y1,x2,y2) == 0 ) ++ans;
                x1 += var[r][0], y1 += var[r][1];
                x2 += var[r][2], y2 += var[r][3];
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}
