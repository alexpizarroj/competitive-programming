#include <cstdio>
#include <cstdlib>

#include <iostream>
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
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int t, n, i, j, yes, no, caseNo = 1;
	UF* uf;
	char c;

	scanf("%d", &t);
	cin.ignore(2);
	while ( t-- )
	{
	    scanf("%d", &n); getchar();
	    uf = new UF(n);
	    yes = no = 0;
	    while ( true )
	    {
	        if( scanf("%c", &c) == EOF ) break;
            if( c != '\n' )
            {
                scanf("%d %d", &i, &j); getchar();
                i--; j--;
                if( c == 'c' )
                    uf->connect(i,j);
                else if ( uf->isConnected(i,j) )
                    yes++;
                else
                    no++;
            } else break;
	    }
	    delete uf;
	    if( caseNo++ != 1 ) printf("\n");
	    printf("%d,%d\n", yes, no);
	}

    return 0;
}
