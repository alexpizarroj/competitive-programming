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

char line[6];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int caseNo=1;

    while( 1 )
    {
        gets(line); if(line[0]=='*') break;
        if( strcmp(line,"Hajj") == 0 )
            printf("Case %d: Hajj-e-Akbar\n",  caseNo++);
        else
            printf("Case %d: Hajj-e-Asghar\n", caseNo++);
    }

    return 0;
}
