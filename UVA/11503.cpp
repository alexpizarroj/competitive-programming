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
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()
#define SET(a,v) memset(a, v, sizeof(a))


class UF
{
	public:
        int *id, *sz;
        int n;

        UF(int N)
        {
            n = N;
            id = new int[N];
            sz = new int[N];
            clear();
        }
        ~UF()
        {
            delete [] id;
            delete [] sz;
        };

        void connect(int i, int j)
        {
            int ri = root(i);
            int rj = root(j);
            if( ri != rj )
            {
                if( sz[ri] > sz[rj] )   { id[rj] = ri;  sz[ri] += sz[rj]; }
                else                    { id[ri] = rj;  sz[rj] += sz[ri]; }
            }
        }

        bool isConnected(int i, int j) { return root(i) == root(j); }

        void clear()
        {
            for(int i=0; i<n; i++)
            {
                id[i] = i;
                sz[i] = 1;
            }
        }

		int root(int i)
        {
            while ( i != id[i] )
            {
                id[i] = id[id[i]];
                i = id[i];
            }
            return i;
        }
};


UF uf(100000);
map<string,int> m;
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int t, f, nextId, id1, id2;
    char name1[21], name2[21];
    string s1, s2;

    scanf("%d", &t); getchar();
    while( t-- )
    {
        uf.clear();
        m.clear();
        nextId = 0;

        scanf("%d", &f); getchar();
        while( f-- )
        {
            scanf("%s %s", name1, name2); getchar();

            s1 = string(name1);
            s2 = string(name2);
            if( m.count(s1) == 0 )
            {
                id1 = nextId;
                m[s1] = nextId++;
            }
            else
                id1 = m[s1];
            if( m.count(s2) == 0 )
            {
                id2 = nextId;
                m[s2] = nextId++;
            }
            else
                id2 = m[s2];

            uf.connect( id1, id2 );
            printf("%d\n", uf.sz[uf.root(id1)] );
        }
    }

    return 0;
}
