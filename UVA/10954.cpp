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
#include <cctype>
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define set(a,v) memset(a, v, sizeof(a))
#define len(a) (int)(a.length())


int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int n,i,val,cost,sum;
    multiset<int> s;

    while(1)
    {
        scanf("%d", &n); if( !n ) break;
        s.clear();
        FOR(i,n)
        {
            scanf("%d", &val);
            s.insert(val);
        }

        cost=0;
        while( s.size() != 1 )
        {
            sum = *(s.begin()) + *(++s.begin());
            s.erase(s.begin(), ++(++s.begin()) );
            s.insert(sum);
            cost += sum;
        }

        printf("%d\n", cost);
    }

    return 0;
}
