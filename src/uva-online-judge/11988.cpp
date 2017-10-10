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


#define MAX 100001
char line[MAX];
list<char> lst;
list<char>::iterator it;
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    set(line,0);
	#endif

    int i,len;
    while( gets(line) != NULL )
    {
        lst.clear();
        it=lst.begin();
        len=strlen(line);
        FOR(i,len)
        {
            if( line[i]=='[' )      it=lst.begin();
            else if( line[i]==']')  it=lst.end();
            else                    lst.insert(it, line[i]);
        }
        for(it=lst.begin(); it!=lst.end(); it++)
            printf("%c", *it);
        puts("");
    }

    return 0;
}
