#include <stdio.h>

using namespace std;

static int n, m; // lines, str len
static char data[100][101];
static int i, j;

inline void add(int line, int pos) {
    if( !(line > -1 && pos > -1 && line < n && pos < m) ) return;
    if(data[line][pos] != '*') data[line][pos]++;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int caseNo = 1;
	bool firstDone = false;

	while (scanf("%d %d\n", &n, &m) != EOF) {
	    // Entrada
        if (!(n+m)) break;
        for(i = 0; i != n; i++) gets(data[i]);
        // Resolucion
        for(i = 0; i != n; i++) for (j = 0; j != m; j++) if(data[i][j] == '.') data[i][j] = '0';
        for(i = 0; i != n; i++) for (j = 0; j != m; j++)  if(data[i][j] == '*') {
            add(i-1, j);
            add(i+1, j);
            add(i, j-1);
            add(i, j+1);
            add(i-1, j-1);
            add(i+1, j-1);
            add(i-1, j+1);
            add(i+1, j+1);
        }
        // Salida
        if(firstDone) printf("\n");
        printf("Field #%d:\n", caseNo);
        for(i = 0; i != n; i++) printf("%s\n", data[i]);
        caseNo++; firstDone = true;
	}

    return 0;
}
