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

int v[10000];

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int n, q, i, value;
    int idx, caseNo = 1;

    while( true )
    {
        scanf("%d %d", &n, &q); if( n == q && q == 0 ) break;
        for(i=0; i<n; i++) scanf("%d", v+i);
        sort(v, v+n);

        printf("CASE# %d:\n", caseNo++);
        for(i=0; i<q; i++)
        {
            scanf("%d", &value);
            idx = lower_bound(v,v+n, value) - v;
            if( idx != n && v[idx] == value )
                printf("%d found at %d\n", value, idx+1);
            else
                printf("%d not found\n", value);
        }
    }

    return 0;
}
