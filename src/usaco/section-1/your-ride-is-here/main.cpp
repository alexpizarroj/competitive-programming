/*
ID: alex.pi1
PROG: ride
LANG: C++
*/
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


int main()
{
    freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);

    char a[7], b[7];
    int alen, blen, n, m, i;

    while ( gets(a) != NULL && gets(b) != NULL) {
        alen = strlen(a);
        blen = strlen(b);
        n = m = 1;
        FORX(i,0,alen) n *= a[i]-'A'+1;
        FORX(i,0,blen) m *= b[i]-'A'+1;
        printf("%s\n", n%47 == m%47 ? "GO" : "STAY");
    }

    return 0;
}
