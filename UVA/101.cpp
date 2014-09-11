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

#define MAXN 24
struct Block {
    int r,c;
    Block() {}
    Block(int r, int c) : r(r), c(c) {}
} v[MAXN];
short p[MAXN][MAXN]; // blocks world
short cnt[MAXN]; // how many blocks in x row


// Move block x to (r,c)
void moveBlock(int block, int r2, int c2) {
    int r=v[block].r, c=v[block].c;
    p[r][c]=0;
    p[r2][c2]=block;
    v[block].r=r2;
    v[block].c=c2;
    cnt[r]--;
    cnt[r2]++;
}

void removeStack(int block) {
    int c=v[block].c+1, r=v[block].r, b;
    while(c<MAXN) {
        b=p[r][c];
        if(b!=0) {
            moveBlock(b,b,0);
            c++;
        } else break;
    }
}

void move(int block, int dstBlock) {
    int dstR=v[dstBlock].r, dstC=v[dstBlock].c+1;
    int r=v[block].r, c=v[block].c;

    while(p[dstR][dstC]!=0)
        dstC++;
    while(p[r][c]!=0)
        moveBlock(p[r][c++], dstR, dstC++);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n,i,j;
    char sa[5], sb[5];

    while(scanf("%d",&n)!=EOF) {
        // Entrada
        if(n<2) break;
        memset(p,0,sizeof p);
        FORX(i,0,n) {
            p[i][0]=i;
            cnt[i]=1;
            v[i].r=i;
            v[i].c=0;
        }
        // Resolucion
        while (1)  {
            scanf("%s",sa);
            if(sa[1]!='u') {
                scanf("%d %s %d", &i,sb,&j);
                if(i==j || v[i].r==v[j].r) continue;
                if(sa[1]=='o') removeStack(i);
                if(sb[1]=='n') removeStack(j);
                move(i,j);
            } else break;
        }
        // Salida
        FORX(i,0,n) {
            printf("%d:",i);
            FORX(j,0,cnt[i]) printf(" %d",p[i][j]);
            printf("\n");
        }
    }

    return 0;
}
