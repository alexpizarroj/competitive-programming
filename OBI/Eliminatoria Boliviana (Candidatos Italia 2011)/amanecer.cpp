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
#define MAXV 200
#define MAXDEGREE 200

using namespace std;

typedef struct {
    int edges[MAXV+1][MAXDEGREE];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
} graph;
static graph g1;
static bool discovered[MAXV+1];
static int parent[MAXV+1], currentDeletedVertex = 0;
inline bool valid_edge(int v) { return v!=currentDeletedVertex; }


void insert_edge(graph *g, int x, int y, bool directed) {
    g->edges[x][g->degree[x]] = y;
    g->degree[x]++;
    if(!directed)
        insert_edge(g, y, x, true);
    else
        g->nedges++;
}

void read_graph(graph *g, bool directed) {
    int i, m, x, y;
    // Init
    g->nvertices = 0;
    g->nedges = 0;
    for(i=1; i<=MAXV; i++) g->degree[i] = 0;
    // Read
    scanf("%d %d", &(g->nvertices), &m);
    for(i=1; i<=m; i++) {
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}

void dfs(graph *g, int v) {
    int i, y;
    for(i=0; i<g->degree[v]; i++) {
        y = g->edges[v][i];
        if(valid_edge(y)) {
            if( !discovered[y] ) {
                parent[y] = v;
                discovered[y] = true;
                dfs(g, y);
            }
        }
    }
}

bool isConnected(graph *g) {
    // Inicializar
    int i, v=1, k = 0;
    for(i=1; i<=g->nvertices; i++) {
        discovered[i] = false;
        parent[i] = -1;
    }
    // Explorar grafo
    if(currentDeletedVertex==v) v++;
    discovered[v] = true;
    dfs(g, v);
    for(i=1; i<=g->nvertices; i++)
        if(parent[i]==-1 && i != currentDeletedVertex) k++;

    return (k==1);
}

int main() {
    #ifndef JUDGE
    freopen("amanecer.in", "r", stdin);
	freopen("amanecer.mine.out", "w", stdout);
    #endif

    int NC, i, ans;

    scanf("%d", &NC);
    while (NC--) {
        // Entrada
        read_graph(&g1, false);

        // Resolucion
        ans = 0;
        for(i = 1; i <= g1.nvertices; i++) {
            currentDeletedVertex = i;
            if( isConnected(&g1) == false) ans++;
        }

        // Salida
        printf("%d\n", ans);
    }

    #ifndef JUDGE
    fclose(stdout);
    #endif
    return 0;
}
