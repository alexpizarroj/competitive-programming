#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>

#define FORX(i,start,end) for(i=start;i<end;i++)
#define FORY(i,start,end) for(i=start;i<=end;i++)

using namespace std;

#define MAX 32767
int v[MAX+1];
int memo[MAX+1];
int t;


int solve(int idx)
{
    if( memo[idx] != 0) return memo[idx];

    int i, n = v[idx], best = 1;
    FORX(i,idx + 1,t)
        if( v[i] <= n ) best = max(best, 1 + solve(i));

    return memo[idx] = best;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, i, best;
    int caseNo = 1;

    while ( true )
    {
        // Entrada
        scanf("%d", &n);
        if( n == -1 ) break;
        memset(memo, 0 , sizeof memo);
        i = 0;
        while ( n != -1 )
        {
            v[i++] = n;
            scanf("%d", &n);
        }
        t = i;
        // Resolucion
        best = 0;
        FORX(i,0,t) best = max(best, solve(i));
        // Salida
        if( caseNo != 1 ) printf("\n");
        printf("Test #%d:\n", caseNo++);
        printf("  maximum possible interceptions: %d\n", best);
    }

    return 0;
}
