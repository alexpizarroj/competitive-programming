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

struct Par {
    Par() {}
    Par(int _valor, int _pos) { valor = _valor; pos = _pos; }
    int valor;
    int pos;
};
inline bool operator <(Par a, Par b) { return ( a.valor < b.valor ); }

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int z,i,m,l;
    int next,cnt,caseNo=1;
    set< Par > s;

    while( scanf("%d %d %d %d", &z, &i, &m, &l), (z+i+m+l)!=0 )
    {
        s.clear(); cnt=1;
        s.insert( Par(l,cnt++) );
        while(1)
        {
            next = ( z*l + i ) % m;
            if( s.count( Par(next,0) ) == 1)
            {
                Par p = *s.find(Par(next,0));
                printf("Case %d: %d\n", caseNo++, cnt-p.pos);
                break;
            }
            else
                s.insert( Par(l=next, cnt++) );
        }
    }

    return 0;
}
