#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <climits>
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()
#define SET(a,v) memset(a, v, sizeof(a))


int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int t, v[20], n, i;

    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d", &n);
        FOR(i,n) scanf("%d", v+i);
        printf("%d\n", 2*(*max_element(v,v+n) - *min_element(v,v+n)) );
    }

    return 0;
}
