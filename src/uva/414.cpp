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

    int n, i, cnt, m;
    char line[30];
    vector<int> spaces;

    while( true )
    {
        scanf("%d", &n); getchar();
        if(!n) break;

        spaces.clear();
        while( n-- )
        {
            gets(line);
            spaces.push_back( count(line,line+strlen(line),' ') );
        }

        cnt=0; m = *min_element(spaces.begin(), spaces.end());
        for(i=0;i<spaces.size();i++) cnt += spaces[i]-m;
        printf("%d\n", cnt);

    }

    return 0;
}
