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

    int n;
    char line[31];
    int low=1, up=10;
    set(line,0);

    while(1)
    {
        scanf("%d", &n); getchar();
        if( n == 0 ) break;
        gets(line);

        if( line[4]=='h' )      up=min(up,n-1);
        else if( line[4]=='l' ) low=max(low,n+1);
        else
        {
            if( low <= up && low <= n && n <= up )
                puts("Stan may be honest");
            else
                puts("Stan is dishonest");
            low=1; up=10;
        }
    }

    return 0;
}
