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

int getflow(const string& flow)
{
    int ret = 0, mult = 1;
    fup(i,0,flow.size())
    {
        ret += (flow[i]-'0')*mult;
        mult <<= 1;
    }
    return ret;
}

int main()
{
    int tc, outlets[1029], n, l, ans;
    bool devices[1029], valid;
    string flow;
    
    cin >> tc;
    fupi(caso, 1, tc)
    {
        printf("Case #%d: ", caso);
        
        cin >> n >> l;
        memset(devices, 0, sizeof devices);
        fup(i,0,n) 
        {
            cin >> flow;
            outlets[i] = getflow(flow);
        }
        fup(i,0,n)
        {
            cin >> flow;
            devices[getflow(flow)] = true;
        }
        
        int topmask = 1<<l, cand;
        ans = INF;
        fup(mask,0,topmask)
        {
            valid = true;
            fup(i,0,n)
            {
                int changed = outlets[i];
                fup(bit,0,l) if ( mask&(1<<bit) ) changed ^= (1<<bit);
                if ( devices[changed] == false ) { valid = false; break; }
            }
            if ( valid )
            {
                cand = 0;
                fup(bit,0,l) if ( mask&(1<<bit) ) ++cand;
                if ( cand < ans ) ans = cand;
            }
        }
        if ( ans == INF ) puts("NOT POSSIBLE"); else printf("%d\n", ans);
    }
    return 0;
}
