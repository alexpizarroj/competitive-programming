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

#define MAX 100
#define MIN -1280000

using namespace std;


int n;
int t[MAX][MAX], v[MAX];


int getMaxSum(const int v[]) {
    int i,sum=0,maxN=MIN;
    FORX(i,0,n) {
        sum+=v[i];
        maxN=max(maxN,sum);
        if(sum<0) sum=0;
    }
    return maxN;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

    int i,j,k,maxN;

    while (scanf("%d", &n) != EOF) {
        // Entrada
        FORX(i,0,n)
            FORX(j,0,n) scanf("%d", &t[i][j]);
        // Resolucion
        maxN=MIN;
        FORX(i,0,n) {
            memset(v,0,sizeof(v));
            FORX(j,i,n) {
                FORX(k,0,n) v[k] += t[j][k];
                maxN = max(maxN,getMaxSum(v));
            }
        }
        printf("%d\n", maxN);
    }

    return 0;
}
