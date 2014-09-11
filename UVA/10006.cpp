#include <stdio.h>
#define MAX 15

using namespace std;

static int l[15] = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973 };

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, i;
    bool found;

    while ( true ) {
        scanf("%d", &n); if(!n) break;
        found = false;
        for(i = 0; i != MAX; i++) {
            if ( l[i] == n ) {
                printf("The number %d is a Carmichael number.\n", n);
                found = true;
                break;
            }
        }
        if (!found) printf("%d is normal.\n", n);
    }

    return 0;
}
