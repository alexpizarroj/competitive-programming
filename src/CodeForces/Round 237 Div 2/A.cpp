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

int main()
{
        string box[305];
        bool valid;
        int n;
        
        while ( cin >> n, cin )
        {
            fup(i,0,n) cin >> box[i];
            
            valid = true;
            fup(i,0,n) if ( box[i][i] != box[i][n-i-1] || box[i][i] != box[0][0] ) 
            {
                valid = false;
                break;
            }
            fup(i,0,n) fup(j,0,n) if ( j != i && j != n-i-1 && box[i][j] != box[0][1] ) 
            {
                valid = false;
                break;
            }
            if ( box[0][0] == box[0][1] ) valid = false;
            
            cout << ( valid ? "YES" : "NO" ) << endl;
        }
        
	
    return 0;
}
