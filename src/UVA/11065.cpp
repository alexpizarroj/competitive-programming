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
typedef long long       i64;
typedef vector<i64>     vi64;

i64 adjmask[65];
int n, nSets, maxCard;

void backtrack(int p, i64 taken, int size)
{
    if ( taken == (1LL<<n)-1 )
    {
        ++nSets;
        maxCard = max(maxCard, size);
    }
    else
    {
        fore(i,p,n-1) if ( !((taken >> i) & 1) )
        {
            backtrack(i+1, taken | adjmask[i], size+1);
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while ( tc-- )
    {
        int m;
        scanf("%d %d", &n, &m);
        forn(i,n)
        {
            adjmask[i] = (1LL<<i);
        }
        forn(i,m)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            adjmask[x] |= (1LL<<y);
            adjmask[y] |= (1LL<<x);
        }
        nSets = maxCard = 0;
        backtrack(0, 0, 0);
        printf("%d\n%d\n", nSets, maxCard);
    }
    return 0;
}