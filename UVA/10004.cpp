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

#define MAXV 200
#define UNSET -1
#define WHITE 0
#define BLACK 1
struct intbool {
    int v;
    bool color;
    intbool() {}
    intbool(int v, bool color) : v(v), color(color) {}
};
int n;
bool connected[MAXV][MAXV];
short vcolor[MAXV];


bool isBicolored(int startVertex) {
    int i;
    intbool p;
    queue<intbool> q;

    vcolor[startVertex]=WHITE;
    q.push( intbool(startVertex,vcolor[startVertex]) );
    while(!q.empty()) {
        p=q.front();
        q.pop();
        FORX(i,0,n) {
            if(connected[p.v][i]){
                if(vcolor[i]==UNSET) {
                    vcolor[i]=!vcolor[p.v];
                    q.push( intbool(i,vcolor[i]) );
                } else if(vcolor[i]==vcolor[p.v]) return false;
            }
        }
    }

    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int nedges,i,j;
    bool yes;

    while(1) {
        // Entrada
        scanf("%d", &n);
        if(n==0) break;
        scanf("%d", &nedges);
        memset(connected,0,sizeof connected);
        while(nedges--) {
            scanf("%d %d", &i, &j);
            connected[i][j]=connected[j][i]=1;
        }
        // Resolucion
        memset(vcolor,UNSET,sizeof vcolor);
        while(1) {
            FORX(i,0,n)
                if(vcolor[i]==UNSET) break;
            if(i<n) yes=isBicolored(i); else break;
            if(yes==false) break;
        }
        // Salida
        printf("%s\n", yes ? "BICOLORABLE." : "NOT BICOLORABLE.");
    }

    return 0;
}
