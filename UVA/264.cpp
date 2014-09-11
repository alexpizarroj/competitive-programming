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
#define MAX 10000000

using namespace std;


vector<int> v;
int vlen;

int column(int n) {
    int i;
    for(i=0; n>=v[i] && i<vlen; i++);
    return --i;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int i=1, j=4, k, n, m, r, c;

    // Valores precalculados Primer Fila
    do {
        v.push_back(i++);
        v.push_back(i);
        i += j;
        j += 4;
    } while(i<=MAX);
    vlen = v.size();

    while( scanf("%d", &n) != EOF ) {
        // Resolucion
        r = 0; c = column(n);
        k = v[c]; m = c;
        FORX(i,0,m) {
            if(k==n) break;
            r++; c--;
            k++;
        }
        if(k!=n) {
            k++;
            r++;
            m++;
        }
        FORX(i,0,m) {
            if(k==n) break;
            r--; c++;
            k++;
        }
        // Salida
        printf("TERM %d IS %d/%d\n", n, r+1, c+1);
    }

    return 0;
}
