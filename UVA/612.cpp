#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

static int m, n, lim; // Total strs, str len, str len - 1
static int i, j, k, val, cmpData[2];
static char* s[100], *p;


bool cmpStrP(char *x, char *y) {
    for(i = 0; i != 2; i++) {
        p = (i == 0 ? x : y);
        val = 0;
        //
        for(j = 0; j != lim; j++) {
            for(k = j+1; k != n; k++) {
                if(p[j] > p[k]) val++;
            }
        }
        //
        cmpData[i] = val;
    }
    return cmpData[0] < cmpData[1];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int M;
	bool firstDone = false;

	scanf("%d\n", &M);
	while (M--) {
	    // Entrada
	    scanf("%d %d\n", &n, &m);
	    lim = n-1;
        for(i = 0; i != m; i++) {
            p = new char[n+1];
            gets(p);
            s[i] = p;
        }
        // Resolucion
        stable_sort(s, s+i, cmpStrP);
        // Salida
        if(firstDone) printf("\n");
        for(i = 0; i != m; i++) printf("%s\n", s[i]);
        firstDone = true;
	}

    return 0;
}
