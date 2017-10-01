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

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int t,i,n,trees,acorns;
    char x,y;
    char buffer[256];
    map<char, int> mp;
    UF uf(26);

    scanf("%d", &t); getchar();
    while( t-- )
    {
        i = 0;
        mp.clear();
        uf.clear();
        while(1)
        {
            gets(buffer);
            if( buffer[0] == '(' )
            {
                sscanf(buffer, "(%c,%c)", &x, &y);
                if( mp.count(x) == 0 ) mp[x] = i++;
                if( mp.count(y) == 0 ) mp[y] = i++;
                uf.connect(mp[x], mp[y]);
            }
            else if( buffer[0] != '*')
            {
                n = count(buffer, buffer+strlen(buffer), ',') + 1;
                break;
            }
        }

        trees = acorns = 0;
        for(i=0; i<n; i++)
            if( uf.id[i] == i )
            {
                if( uf.sz[i] > 1 ) trees++;
                else               acorns++;
            }

        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
    }

    return 0;
}
