#include <stdio.h>
#include <math.h>

using namespace std;


int count(int x) {
    if(x == 1) return 1;

    int i, lim = sqrt(x)+1, cnt = 0;
    for(i = 1; i != lim; i++)
        if(x%i == 0) {
            if(x/i == i) cnt++; else cnt += 2;
        }
    return cnt;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int c, l, u, best, bestcnt, i, j;

	scanf("%d", &c);
	while (c--) {
		// Entrada
		scanf("%d %d", &l, &u);
		// Resolucion
		best = l; bestcnt = count(l);
		for(i = l+1; i <= u; i++) {
			j = count(i);
			if(j > bestcnt) {
				best = i;
				bestcnt = j;
			}
		}
		// Salida
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, best, bestcnt);
	}

	return 0;
}
