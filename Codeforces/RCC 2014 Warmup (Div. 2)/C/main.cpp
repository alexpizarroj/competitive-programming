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
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;
const int INF = int(1e9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

bool played[1001][1001];
int le[1000000], ri[1000000];

inline bool used(int i, int j) { return played[i][j] || played[j][i]; }

int main()
{
    int n, k, c, m;
    bool valid;
    
    while ( cin >> n >> k, cin )
    {
        m = 0;
        valid = true;
        memset(played, 0, sizeof played);
        fupi(i,1,n)
        {
            c = k;
            fupi(j,1,n) if ( i != j && !used(i, j) )
            {
                le[m] = i, ri[m] = j;
                played[i][j] = played[j][i] = true;
                --c, ++m;
                if ( c == 0 ) break;
            }
            if ( c > 0 )
            {
                valid = false;
                break;
            }
        }
        if ( valid ) 
        {
            assert(m == n*k);
            printf("%d\n", m);
            fup(i,0,m) printf("%d %d\n", le[i], ri[i]);
        } else puts("-1");
    }
	
    return 0;
}
