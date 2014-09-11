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
    int n, a, b, x;
    vector<ii> vec;
    bool used[105];
    
    while ( scanf("%d %d %d", &n, &a, &b) != EOF )
    {
        fup(i,0,a)
        {
            scanf("%d", &x);
            vec.PB( ii(x,1) );
        }
        fup(i,0,b)
        {
            scanf("%d", &x);
            vec.PB( ii(x,2) );
        }
        sort(ALL(vec));
        memset(used, 0, sizeof used);
        fup(i,0,vec.size())
        {
            x = vec[i].first;
            if ( used[x] ) continue;
            used[x] = true;
            printf("%d ", vec[i].second);
        }
        puts("");
    }
	
    return 0;
}
