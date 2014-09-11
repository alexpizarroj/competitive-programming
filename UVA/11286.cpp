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


map<string,int> counting;
map<string,int>::iterator it;
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int n, a[5], i, j, maxval, ans;
    char buffer[16], buffer2[4];
    set(buffer,0); set(buffer2,0);

    while(1)
    {
        scanf("%d", &n); getchar();
        if(!n) break;

        counting.clear();
        FOR(i,n)
        {
            FOR(j,5) scanf("%d", a+j);
            sort(a,a+5);
            strcpy(buffer,"");
            FOR(j,5)
            {
                sprintf(buffer2, "%d", a[j]);
                strcat(buffer, buffer2);
            }
            counting[ string(buffer) ]++;
        }

        maxval=0;
        for(it=counting.begin(); it!=counting.end(); it++)
            maxval=max(maxval, it->second);
        ans=0;
        for(it=counting.begin(); it!=counting.end(); it++)
            if( it->second == maxval ) ans += maxval;
        printf("%d\n", ans);
    }

    return 0;
}
