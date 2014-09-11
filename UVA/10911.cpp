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

#define MAXN 8
#define MAX MAXN*2
#define MAX_COST 30000
#define NOT_TRIED -1
#define STATE dp[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]][b[6]][b[7]][b[8]][b[9]][b[10]][b[11]][b[12]][b[13]][b[14]][b[15]]
struct Punto { double x, y; } v[MAX];
double memo[MAX][MAX], dp[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2];
int n,n2;

inline double dist(Punto a, Punto b) { return hypot(a.x-b.x, a.y-b.y); }


double teamCost(bool* b, int quedan) {
    if(STATE==STATE) return STATE;

    int i,j,k=quedan-2;
    double cost=MAX_COST,a;

    FORX(i,0,n2) {
        if(b[i]) continue;
        FORX(j,0,n2) {
            if(b[j]) continue;
            if(i!=j) {
                if(quedan==2) {
                    return STATE=memo[i][j];
                } else {
                    b[i]=b[j]=true;
                    a=memo[i][j]+teamCost(b,k);
                    b[i]=b[j]=false;
                    cost=min(cost,a);
                }
            }
        }
    }

    return STATE=cost;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int i,j,caso=1;
    bool b[MAX];

    while (1) {
        // Entrada
        scanf("%d", &n);
        if(n==0) break;
        n2=n*2;
        FORX(i,0,n2) scanf("%*s %lf %lf", &v[i].x, &v[i].y);
        FORX(i,0,n2) FORX(j,0,n2) memo[i][j]=dist(v[i],v[j]);
        memset(b,0,sizeof(b));
        memset(dp,NOT_TRIED,sizeof(dp));

        printf("Case %d: %.2lf\n", caso++, teamCost(b,n2));
    }

    return 0;
}
