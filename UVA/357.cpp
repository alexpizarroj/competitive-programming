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


#define MAX 30000
typedef unsigned long long ull;
ull ans[MAX+1];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

	int coin[] = {1, 5, 10, 25, 50};
    int i, j;

    ans[0] = 1;
    for(i=0; i<5; i++)
        for(j=coin[i]; j<=MAX; j++)
            ans[j] += ans[ j-coin[i] ];

    while( scanf("%d", &i) != EOF )
    {
        if( ans[i] ==  1 )
            printf("There is only 1 way to produce %d cents change.\n", i);
        else
            printf("There are %llu ways to produce %d cents change.\n", ans[i], i);
    }

    return 0;
}
