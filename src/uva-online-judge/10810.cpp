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
#define MAX 500000 // maxima cantidad de elementos a ordenar

using namespace std;

int v[MAX], sortedV[MAX];

long long mergeSort(int *V, int lo, int hi) {
    if(lo>=hi) return 0;
    else {
        int m1=(lo+hi)/2, m2=m1+1;
        long long r=0, rA, rB;
        int i=lo, j=m2, k=0;

        rA = mergeSort(V, lo, m1);
        rB = mergeSort(V, m2, hi);

        while(i<=m1 && j<=hi) {
            if(V[j]<V[i]) {
                r+= (m1-i+1);
                sortedV[k++] = V[j++];
            } else
                sortedV[k++] = V[i++];
        }
        if(i>m1) { i=j; j=hi; } else j=m1;
        while(i<=j) sortedV[k++] = V[i++];

        memcpy(V+lo, sortedV, (hi-lo+1)*sizeof(int));
        return r+rA+rB;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int n, i;

	while ( scanf("%d", &n) != EOF && n != 0 )
	{
        FORX(i,0,n) scanf("%d", &v[i]);
        printf("%lld\n", mergeSort(v, 0, n-1));
	}

    return 0;
}
