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

int main()
{
    double c, f, x, ans, rate, penalty, candidate;
    int tc;
    
    cin >> tc;
    fupi(caseno, 1, tc)
    {
        cin >> c >> f >> x;
        rate = 2, penalty = 0;
        ans = x/rate;
        // Infinite loops are awesome, I wish I needed more :/
        while ( true )
        {
            penalty += c/rate;
            rate += f;
            candidate = penalty + x/rate;
            if ( candidate < ans ) ans = candidate; else break;
        }
        // They see my output, they hatin'
        printf("Case #%d: %.8lf\n", caseno, ans);
    }
    
    return 0;
}
