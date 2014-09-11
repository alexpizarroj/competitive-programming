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


char line[100];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    set(line,0);
	#endif

    int T,t,ans,r,c,m,n,i,j,maxval;
    int cnt[256];

    scanf("%d", &T); getchar();
    REP(t,T)
    {
        ans=0;
        set(cnt,0);
        scanf("%d %d %d %d", &r, &c, &m, &n); getchar();

        REP(i,r)
        {
            gets(line);
            FOR(j,c) cnt[(int)line[j]]++;
        }
        maxval = *max_element( cnt+'A', cnt+'Z'+1 );
        for(i='A'; i<='Z'; i++)
            if( cnt[i] == maxval ) ans += cnt[i]*m; else ans += cnt[i]*n;

        printf("Case %d: %d\n", t, ans);
    }

    return 0;
}
