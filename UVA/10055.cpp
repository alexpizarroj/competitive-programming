#include <stdio.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	unsigned long int a, b;

	while(scanf("%lu", &a) != EOF) {
	    scanf("%lu", &b);
	    printf("%lu\n", (a>b ? a-b : b-a));
    }

    return 0;
}
