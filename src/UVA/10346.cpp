#include <stdio.h>
#define INT unsigned long long

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    INT n, k, total;

    while ( scanf("%llu %llu", &n, &k) != EOF ) {
        total = 0;
        while ( n >= k) {
            total += n-n%k;
            n = n%k + n/k;
        }
        total += n;
        printf("%llu\n", total);
    }

    return 0;
}
