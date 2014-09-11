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

class UF
{
    private:
        int *id, *sz;

        int root(int i)
        {
            while ( i != id[i] )
            {
                id[i] = id[id[i]];
                i = id[i];
            }
            return i;
        }
    public:
        int n;

        UF(int N)
        {
            int i;
            n = N;
            id = new int[N];
            sz = new int[N];
            FORX(i,0,n)
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
            if( sz[ri] > sz[rj] )   { id[rj] = ri;  sz[ri] += sz[rj]; }
            else                    { id[ri] = rj;  sz[rj] += sz[ri]; }
        }

        bool isConnected(int i, int j) { return root(i) == root(j); }

        int countGroups()
        {
            int i,cnt=0;
            FORX(i,0,n)
                if( i==id[i] ) cnt++;
            return cnt;
        }
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, m, i, j;
    int caseNo = 1;
    UF* uf;

    while ( scanf("%d %d", &n, &m) != EOF && !( n == 0 && m == 0 ) )
    {
        uf = new UF(n);
        while ( m-- )
        {
            scanf("%d %d", &i, &j);
            (*uf).connect(i-1, j-1);
        }
        printf("Case %d: %d\n", caseNo++, (*uf).countGroups());
        delete uf;
    }

    return 0;
}
