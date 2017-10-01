#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int k, n, m, x, y;
	char s[3]; s[3] = 0;

	while ( true ) {
	    // Entrada
        scanf("%d", &k); if(!k) break;
        scanf("%d %d", &n, &m);
        // Salidas
        while (k--) {
            scanf("%d %d", &x, &y);
            if (n == x || m == y) { printf("divisa\n"); continue; }
            s[0] = (y < m ? 'S':  'N');
            s[1] = (x < n ? 'O' : 'E');
            printf("%s\n", s);
        }
	}

    return 0;
}
