#include <cstdlib>
#include <cstdio>
#include <iostream>
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
using namespace std;

int vec[1000000];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n, m, idx, nShared, k;

	while ( scanf("%d %d", &n, &m), (n || m) )
	{
	    fup(i,0,n) scanf("%d", vec+i);
	    idx = nShared = 0;
	    fup(i,0,m)
	    {
            scanf("%d", &k);
            while ( idx < n && vec[idx] < k ) idx++;
            if ( vec[idx] == k ) nShared++, idx++;
	    }
	    printf("%d\n", nShared);
	}

    return 0;
}
