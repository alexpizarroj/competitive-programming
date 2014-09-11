// IO
#include <iostream>
#include <cstdio>
// STL
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;
// STRINGS
#include <string>
#include <cstring>
// OTROS
#include <cstdlib>
#include <memory.h>
#include <cmath>
// MACROS
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()


int vh[10001];

int main() {
    //freopen("data.in", "r", stdin);

    int l, h, r, i, mostR = 0, curH, cnt=0;

    memset(vh, 0, sizeof vh);
    while( scanf("%d %d %d", &l, &h, &r) != EOF )
    {
        for(i=l; i<r; i++)
            if( h > vh[i] ) vh[i] = h;
        mostR = max(r, mostR);
    }

    curH = 0;
    for(i=0; i<=mostR;i++)
    {
        if( vh[i] != curH )
        {
            if( cnt )
                printf(" %d %d", i, vh[i]);
            else
                printf("%d %d", i, vh[i]);
            curH = vh[i];
            cnt++;
        }
    }
    puts("");

    return 0;
}
