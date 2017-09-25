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
#define ALL(v) (v).begin(), (v).end()
#define SET(a,v) memset(a, v, sizeof(a))

typedef pair<int,int> pii;
bool cmp(pii a, pii b) {
    if( a.second != b.second )
        return a.second < b.second;
    else
        return a.first < b.first;
}

char buffer[10001];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    vector<pii> v;
    vector<pii>::iterator it;
    int n, p, i, cnt;
    bool first;

    scanf("%d", &n); getchar();
    while( n-- )
    {
        v.clear(); i=1;
        scanf("%d", &p); getchar();
        while(  gets(buffer) != NULL && strcmp(buffer, "") != 0)
        {
            cnt = count(buffer, buffer+strlen(buffer), ' ') + 1;
            v.push_back( make_pair(i++, cnt) );
        }

        sort(v.begin(), v.end(), cmp);
        cnt = v[0].second;
        first = true;
        for(it = v.begin(); it != v.end(); it++)
        {
            if( it->second != cnt ) break;

            if( first ) printf("%d", it->first);
            else        printf(" %d", it->first);

            first = false;
        }
        puts("");
    }

    return 0;
}
