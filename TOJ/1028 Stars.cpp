#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <list>
#include <sstream>
#include <string>
#include <cstring>

#include <memory.h>
#include <algorithm>
#include <cmath>

#define FORX(i,start,end) for(i=start;i<end;i++)
#define FORY(i,start,end) for(i=start;i<=end;i++)

using namespace std;


#define MAX 32001
int n=MAX;
int v[MAX], t[MAX];
map<long long, long long> mp;

long long sum(int x)
{
	long long result = 0;
	for(int i = x; i >= 0; i = (i & (i+1)) - 1)
		result += t[i];
	return result;
}

void inc(int x, int delta)
{
    v[x] += delta;
	for(int i = x; i < n; i = (i | (i+1)))
		t[i] += delta;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

    int scnt, i,j,x,y, lvl, maxN = 0;
    map<long long, long long>::iterator it;

    while( scanf("%d", &scnt) != EOF ) {
        memset(t, 0, sizeof(t));
        memset(v, 0, sizeof(v));
        mp.clear();
        FORX(i,0,scnt) {
            scanf("%d %d", &x, &y);
            lvl = sum(x);
            if( mp.find(lvl)!=mp.end() ) mp[lvl]++; else mp[lvl]=1;
            inc(x,1);
            maxN = max(maxN, lvl);
            //FORY(j,0,maxN) printf(" %d", v[j]); printf("\n----\n");
        }
        FORX(i,0,scnt) {
            it = mp.find(i);
            if( it!=mp.end() )
                printf("%lld\n", (*it).second);
            else
                printf("0\n");

        }
    }

    return 0;
}
