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


char separator[61], line[61], pattern[12];

void PrintList(const vector<string> &v, int maxlen)
{
    int sz = (int)v.size();
    int cols = min( 1 + (60-maxlen)/(maxlen+2), sz);
    int rows = ceil(v.size()/(float)cols);
    int i,j;

    strcpy(pattern, "%-");
    sprintf(pattern+2, "%d", maxlen+2);
    strcat(pattern, "s");

    printf("%s\n", separator);
    FOR(i,rows)
    {
        FOR(j,cols)
        {
            if( i+j*rows < sz )
                printf( (i+(j+1)*rows) < sz ? pattern : "%s", v[i+j*rows].c_str());
        }
        puts("");
    }
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
	#endif

    int n,maxlen;
    vector<string> v;
    strcpy(separator, string(60,'-').c_str() );

    while( scanf("%d", &n) != EOF )
    {
        getchar();
        v.clear(); maxlen=0;
        while( n-- )
        {
            gets(line);
            v.push_back( string(line) );
            maxlen = max(maxlen, (int)strlen(line));
        }
        sort(v.begin(), v.end());
        PrintList(v, maxlen);
    }

    return 0;
}
