#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

static int list[3000], i, j, lim;
static bool v[3000];


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int n;
	bool jolly;

	while (scanf("%d", &n) != EOF) {
	    // Entrada
        memset(v, 0, sizeof(bool)*n);
        for(i = 0; i != n; i++) scanf("%d", &list[i]);
        // Resolucion
        lim = n-1; jolly = true;
        for(i = 0, j = 1; i != lim; i++, j++) v[abs(list[i]-list[j])-1] = true;
        for(i = 0; i != lim; i++) if(!v[i]) { jolly = false; break; }
        // Salida
        if(jolly) printf("Jolly\n"); else printf("Not jolly\n");
	}

    return 0;
}
