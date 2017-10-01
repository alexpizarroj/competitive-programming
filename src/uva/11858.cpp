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


#define MAX 1000005
int n;
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

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int i;
    while( scanf("%d", &n) != EOF )
    {
        FOR(i,n) scanf("%d", v+i);
        printf("%lld\n", mergeSort(v,0,n-1));
    }

    return 0;
}
