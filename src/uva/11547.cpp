#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t, n;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        n = ((((n * 567 / 9) + 7492) * 235 / 47) - 498) / 10;
        if(n < 0) n *= -1;
        printf("%d\n", n % 10);
    }

    return 0;
}
