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
typedef vector<int> vi;
const int INF = int(1e9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;

int main()
{
    vi cards[2], inter(10);
    int tc, row, value;
    
    cin >> tc;
    fupi(TC, 1, tc)
    {
        // Overkill solution right ahead, careful!
        fup(k,0,2)
        {
            cards[k].clear();
            cin >> row;
            fupi(r,1,4) fupi(c,1,4) 
            {
                cin >> value;
                if ( r == row ) cards[k].PB(value);
            }
            sort(ALL(cards[k]));
        }
        value = distance(
            inter.begin(), 
            set_intersection(ALL(cards[0]), ALL(cards[1]), inter.begin())
        );
        
        // Extremely sexy output comes next
        printf("Case #%d: ", TC);
        if ( value == 0 ) printf("Volunteer cheated!");
        else if ( value == 1 ) printf("%d", inter[0]);
        else printf("Bad magician!");
        puts("");
    }
	
    return 0;
}
