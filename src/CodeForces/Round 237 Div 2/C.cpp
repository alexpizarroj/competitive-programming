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

int f[100005];
vector<vi> lst; // vertext list to classify them according to their dist

int main()
{
    int n, k, d, maxd;
    
    while ( ~scanf("%d %d", &n, &k) )
    {
        memset(f, 0, sizeof f);
        lst.assign(n, vi());
        maxd = 0;
        fupi(i,1,n)
        {
            scanf("%d", &d);
            lst[d].PB(i);
            ++f[d];
            maxd = max(maxd, d);
        }
        
        // Solution exists if and only if...
        bool solvable = true;
        if ( f[0] != 1 || f[1] > k ) solvable = false;
        if ( solvable )
        {
            fupi(i,2,maxd) if ( f[i] > (long long)(k-1)*f[i-1] ) 
            {
                solvable = false;
                break;
            }
        }
        
        // Generate solution
        if ( !solvable ) puts("-1");
        else 
        {
            printf("%d\n", n-1);
            // From source to layer 1
            fup(i,0,lst[1].size()) printf("%d %d\n", lst[0][0], lst[1][i]);
            // From layer i-1 to layer i
            fupi(i,2,maxd)
            {
                int wanted = lst[i].size();
                int cur = 0, rem = k-1;
                while ( wanted > 0 )
                {
                    if ( rem == 0 ) ++cur, rem = k-1;
                    printf("%d %d\n", lst[i-1][cur], lst[i][wanted-1]);
                    --rem, --wanted;
                }
            }
        }
    }
	
    return 0;
}
