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

#define MAXQ 100000
#define MAXN 100005
#define PCI pair<char,int>

PCI input[MAXQ];
map<int, pair<int,int> > idx; // numero (-) par: indice, y numero de veces que aparece
int n, a[MAXN];
struct nodo { int mcd; } T[MAXN*4];


int mcd(int a, int b) {
    if(b>a) swap(a,b);
    while(b!=0) {
        a=a%b;
        swap(a,b);
    }
    return a;
}

void update(int b, int e, int node, int i, int val)
{
    if(i < b || i > e) return;

    if( b == e ) {
        T[node].mcd = val;
    }
    else
    {
        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;

        update(b, mid, le, i, val);
        update(mid + 1, e, ri, i, val);

        T[node].mcd  = mcd(T[le].mcd, T[ri].mcd);
    }
}

void init(int b, int e, int node)
{
    if(b == e) {
        T[node].mcd = a[b];
    }
    else
    {
        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
        init(b, mid, le);
        init(mid + 1, e, ri);

        T[node].mcd  = mcd(T[le].mcd, T[ri].mcd);
    }
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

    int n2, q, i, j, k, num;
    pair<int,int> *p; //indice, numero de veces
    char c, s[2];

    while( scanf("%d", &q) != EOF ) {
        // Almacenamiento de entradas
        idx.clear();
        k=j=0; getchar();
        while(q--) {
            scanf("%s %d", s, &num); getchar();
            input[k].first = s[0];
            input[k++].second = num;
            if( idx.find(num) == idx.end() ) idx[num] = make_pair(j++, 0);
        }
        n=j; n2=n-1;
        memset(a,0,sizeof(int)*n);
        init(0,n2,0);
        // Procesamiento
        FORX(i,0,k) {
            c=input[i].first;
            num=input[i].second;
            p = &idx[num];
            if(c=='+') {
                if(p->second==0) update(0,n2,0,p->first,num);
                p->second++;
            } else {
                if(p->second==1) update(0,n2,0,p->first,0);
                p->second--;
            }
            printf("%d\n", max(1, T[0].mcd));
        }
    }

	return 0;
}
