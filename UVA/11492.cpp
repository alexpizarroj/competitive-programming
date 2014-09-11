#include <stdio.h>
#include <algorithm>

using namespace std;

static char ages[2000000];


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int n, i;

	while ( true ) {
	    // Entrada
	    scanf("%d\n", &n);
	    if(!n) break;
	    for(i = 0; i != n; i++) scanf("%d", &ages[i]);
	    // Salida
	    sort(ages, ages+n);
	    printf("%d", ages[0]);
	    for(i = 1; i != n; i++) printf(" %d", ages[i]);
	    printf("\n");
	}

    return 0;
}
