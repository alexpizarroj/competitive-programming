#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int C, N, i, j, avg, v[1000];
	float ans;

	scanf("%d", &C);
	while (C--) {
	    // Entrada
	    scanf("%d", &N);
	    avg = 0;
        for(i = 0; i != N; i++) {
            scanf("%d", &v[i]);
            avg += v[i];
        }
        avg /= N;
        // Resolucion
        j = 0;
        for(i = 0; i != N; i++) if( v[i] > avg) j++;
        ans = (float)j / N * 100;
        // Salida
        printf("%.3f%%\n", ans);
	}

    return 0;
}
