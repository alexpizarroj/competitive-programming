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

    int donations=0, t, val;
    char line[20];

    scanf("%d", &t); getchar();
    while( t-- )
    {
        gets(line);
        if( line[0]=='d' )
        {
            sscanf(line, "%*s %d", &val);
            donations += val;
        }
        else
            printf("%d\n", donations);
    }

    return 0;
}
