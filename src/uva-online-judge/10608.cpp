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
            int i;
            n = N;
            id = new int[N];
            sz = new int[N];
            for(i=0; i<n; i++)
            {
                id[i] = i;
                sz[i] = 1;
            }
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

    private:
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

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    UF *uf = NULL;
    int t, n, m, a, b, largest;

    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d %d", &n, &m);
        uf = new UF(n);
        while( m-- )
        {
            scanf("%d %d", &a, &b);
            uf->connect(a-1,b-1);
        }

        largest = 0;
        for(int i=0; i<n; i++)
            if( uf->id[i] == i )
                largest = max(uf->sz[i], largest);
        printf("%d\n", largest);

        delete uf;
    }

    return 0;
}
