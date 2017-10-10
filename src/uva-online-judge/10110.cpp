#include <stdio.h>
#include <math.h>

using namespace std;


int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	unsigned int n; double r;

	while (true) {
	    scanf("%u", &n); if(!n) break;
	    r = sqrt(n);
	    if ( r == trunc(r) ) printf("yes\n");
	    else printf("no\n");
	}

	return 0;
}
