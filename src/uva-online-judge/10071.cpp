#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    long int a, b;

	while(scanf("%ld", &a) != EOF) {
	    scanf("%ld", &b);
	    printf("%ld\n", a*b*2);
    }

    return 0;
}
