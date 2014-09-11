#include <stdio.h>
#include <algorithm>
#define MAX_CUTS 51 //49 cortes maximos + 2 posiciones de inicio y fin del tronco
#define NOT_TRIED 0

using namespace std;

static int c[MAX_CUTS];
static int dp[MAX_CUTS][MAX_CUTS];


void clean() {
    int i, j;
    for(i=0; i<MAX_CUTS; i++)
        for(j=0; j<MAX_CUTS; j++)
            dp[i][j] = NOT_TRIED;
}

int solve(int cost, int start, int end) {
    if(dp[start][end] != NOT_TRIED) return dp[start][end];
    if(start+1==end) {
        dp[start][end] = 0;
        return dp[start][end];
    } else if (start+2==end) {
        dp[start][end] = cost;
        return dp[start][end];
    }

    int i, a1=c[start], a2, a3 = c[end], left, right, best = NOT_TRIED;
    for(i=start+1; i<end; i++) {
        a2 = c[i];
        left = solve(a2-a1, start, i);
        right = solve(a3-a2, i, end);
        if(best == NOT_TRIED)
            best = left+right;
        else
            best = min(best, left+right);
    }

    dp[start][end] = cost+best;
    return dp[start][end];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int l, n, i, ans;

    while ( true ) {
        // Entrada
        scanf("%d", &l); if(!l) break;
        scanf("%d", &n);
        c[0] = 0;
        for(i=1; i<=n; i++) scanf("%d", &c[i]);
        c[n+1] = l;
        // Resolucion
        clean();
        ans = solve(l, 0, n+1);
        // Salida
        printf("The minimum cutting is %d.\n", ans);
    }

    return 0;
}
