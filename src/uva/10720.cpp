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


inline bool cmp(int a, int b) { return a > b; }

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int d[10000], n, i, k, m1, m2;
    bool possible;

    while( scanf("%d", &n), n != 0 )
    {
        for(i=m1=0; i<n; i++)
        {
            scanf("%d", d+i);
            m1 += d[i];
        }
        if( m1%2==1 )
            puts("Not possible");
        else
        {
            possible=true;
            sort(d,d+n,cmp);
            for(k=1;k<=n && possible;k++)
            {
                m1=0;
                FOR(i,k) m1+=d[i];
                //
                m2=k*(k-1);
                for(i=k+1;i<=n;i++) m2+=min(d[i-1],k);
                //
                if( m1 > m2 ) possible = false;
            }
            if(possible)
                puts("Possible");
            else
                puts("Not possible");
        }
    }

    return 0;
}
