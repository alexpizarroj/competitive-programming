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


char s[600];
int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int m,t,i,n,val,ans;
    int cnt[256];
    vector<int> v;

    scanf("%d", &m); getchar();
    REP(t,m)
    {
        gets(s);
        n = strlen(s);
        set(cnt,0);
        v.clear();

        FOR(i,n)
            if( isalpha(s[i]) )
                cnt[ (int)tolower(s[i]) ]++;

        for(i='a';i<='z';i++)
            if( cnt[i] > 0 )
                v.push_back(cnt[i]);

        val=26; ans=0;
        sort(v.begin(), v.end());
        for(i=v.size()-1; i>=0; i--)
            ans += v[i]*val--;

        printf("Case #%d: %d\n", t, ans);
    }

    fclose(stdout);
    return 0;
}
