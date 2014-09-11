#include <stdio.h>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
//#define JUDGE
#define MAX_M 1000
#define MAX_C 500
#define CANT_SOLVE MAX_M+1

using namespace std;

static int mv[MAX_M+1], cv[MAX_C];

int closest(int n, int top) {
    int i = 0;
    while (n >= cv[i] && i < top) i++;
    return i-1;
}

int solve(int n, int top) {
    if( mv[n] != -1 ) return mv[n];
    int i, c, k, val, best = CANT_SOLVE;

    for(i = top; i >= 0; i--) {
        c = cv[i];
        k = n-cv[i];
        if(k == 0)
            val = 1;
        else
            val = 1 + solve(k, closest(k, top+1));
        best = min(best, val);
    }
    mv[n] = best;

    return mv[n];
}

int main() {
    #ifndef JUDGE
    freopen("aduana.in", "r", stdin);
    freopen("aduana.mine.out", "w", stdout);
    #endif

    int NC, m, c, ans;
    int i;

    scanf("%d", &NC);
    while (NC--) {
        // Entrada
        scanf("%d %d", &m, &c);
        for(i = 0; i < c; i++) scanf("%d", &cv[i]);

        // Resolucion
        memset( mv, -1, sizeof(int)*(MAX_M+1) );
        ans = solve(m, closest(m, c));

        // Salida
        if(ans != CANT_SOLVE)
            printf("%d\n", ans);
        else
            printf("Incautado!!\n");
    }

    #ifndef JUDGE
    fclose(stdout);
    #endif
    return 0;
}
