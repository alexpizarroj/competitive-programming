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

#define MAX_M 200
#define MAX_C 20
#define MAX_K 20
#define NOT_TRIED -1
#define CANT_SOLVE -2
int memo[MAX_M+1][MAX_C][MAX_K];
int price[MAX_C][MAX_K+1]; // la posicion 20 se usa para guardar la cantidad total de prendas
int c;


inline int best(int money, int opt1, int opt2) {
    if(opt1>opt2) swap(opt1,opt2);
    //
    if(opt1>money) return min(opt1,opt2);
    else if(opt2>money) return opt1;
    else return max(opt1,opt2);
}

int solve(int m, int row, int col) {
    if(m<0) return CANT_SOLVE;
    if(memo[m][row][col]!=NOT_TRIED) return memo[m][row][col];

    int i,j,k,bestAns=CANT_SOLVE;
    // Caso base
    if(row+1==c) {
        k = price[row][MAX_K];
        FORX(i,0,k) {
            if(i==0)
                bestAns = price[row][i];
            else
                bestAns = best(m, bestAns, price[row][i]);
        }
        if(bestAns>m) bestAns = CANT_SOLVE;
    } else {
        int mo = m-price[row][col];
        k = price[row+1][MAX_K];
        FORX(i,0,k) {
            j = solve(mo,row+1,i);
            if(j==CANT_SOLVE) continue;
            if(i==0)
                bestAns = j+price[row][col];
            else
                bestAns = best(m,bestAns,j+price[row][col]);
        }
    }

    return memo[m][row][col] = bestAns;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int N,m,k;
    int i,j,bestAns;

    scanf("%d", &N);
    while (N--) {
        // Entrada
        scanf("%d %d", &m, &c);
        FORX(i,0,c) {
            scanf("%d", &k);
            price[i][MAX_K] = k;
            FORX(j,0,k) scanf("%d", &price[i][j]);
        }
        // Resolucion
        memset(memo, NOT_TRIED, sizeof memo);
        k=price[0][MAX_K];
        FORX(j,0,k) {
            i = solve(m,0,j);
            if(j==0)
                bestAns = i;
            else
                bestAns = best(m,bestAns,i);
        }
        // Salida
        if(bestAns==CANT_SOLVE)
            printf("no solution\n");
        else
            printf("%d\n", bestAns);
    }

    return 0;
}
