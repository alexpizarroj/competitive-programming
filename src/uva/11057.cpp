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

    int n, i, j, m;
    int bookA, bookB;
    int a[10000];

    while( scanf("%d", &n) != EOF )
    {
        for(i=0; i<n; i++) scanf("%d", a+i);
        sort(a, a+n);
        scanf("%d", &m);

        i = 0; j = n-1;
        while( a[j] >= m ) j--;

        while( i < j )
        {
            if( (a[i]+a[j]) > m )       j--;
            else if( (a[i]+a[j]) < m )  i++;
            else
            {
                bookA = a[i];
				bookB = a[j];
                i++;
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n", bookA, bookB);
        puts("");
    }

    return 0;
}
