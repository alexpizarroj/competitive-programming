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
#define MAXN 1000
#define MAXN2 MAXN+2
#define BLOCK '#'

using namespace std;

static char lab[MAXN2][MAXN2+1];
static bool discovered[MAXN2][MAXN2+1];
typedef struct { int i, j; } NODE;
static queue<NODE> q;


void clear(int d) {
    int i, j, k = d+2;
    for(i = 0; i < k; i++) {
        for(j = 0; j < k; j++) {
            lab[i][j] = BLOCK;
            discovered[i][j] = false;
        }
        lab[i][k] = 0;
    }
    while(!q.empty()) q.pop();
}

int main() {
    #ifndef JUDGE
    freopen("laberinto.in", "r", stdin);
    freopen("laberinto.mine.out", "w", stdout);
    #endif

    char buffer[MAXN2];
    NODE start, end, v, tmp;
    int NC, n, i, j, k;
    bool yes;

    scanf("%d", &NC); getchar();
    while (NC--) {
        // Entrada
        scanf("%d", &n); getchar();
        clear(n);
        for(i = 1; i <= n; i++) {
            gets(buffer);
            for(j = 0, k = 1; j < n; j++, k++) {
                lab[i][k] = buffer[j];
                if(buffer[j] == 'I') {
                    start.i = i; start.j = k;
                } else if(buffer[j] == 'F') {
                    end.i = i; end.j = k;
                }
            }
        }

        // Resolucion
        yes = false;
        v.i = start.i; v.j = start.j;
        q.push(v); discovered[v.i][v.j] = true;
        while (q.empty() == false) {
            v = q.front(); q.pop();
            if(v.i == end.i && v.j == end.j) {
                yes = true;
                break;
            }

            tmp.i = v.i+1; tmp.j = v.j;
            if( lab[tmp.i][tmp.j] != BLOCK && !discovered[tmp.i][tmp.j] ) { q.push(tmp); discovered[tmp.i][tmp.j] = true; }

            tmp.i = v.i-1; tmp.j = v.j;
            if( lab[tmp.i][tmp.j] != BLOCK && !discovered[tmp.i][tmp.j] ) { q.push(tmp); discovered[tmp.i][tmp.j] = true; }

            tmp.i = v.i; tmp.j = v.j+1;
            if( lab[tmp.i][tmp.j] != BLOCK && !discovered[tmp.i][tmp.j] ) { q.push(tmp); discovered[tmp.i][tmp.j] = true; }

            tmp.i = v.i; tmp.j = v.j-1;
            if( lab[tmp.i][tmp.j] != BLOCK && !discovered[tmp.i][tmp.j] ) { q.push(tmp); discovered[tmp.i][tmp.j] = true; }

        }

        // Salida
        printf("%s\n", (yes ? "Si" : "No"));
    }

    #ifndef JUDGE
    fclose(stdout);
    #endif
    return 0;
}
