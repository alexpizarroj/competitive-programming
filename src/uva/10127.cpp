#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, d, m, pm;

    while (scanf("%d", &n) != EOF) {
        d = 1; m = 1%n; pm = m;
        while (m != 0) {
            pm = (10*pm)%n;
            m = (m+pm)%n;
            d++;
        }
        printf("%d\n", d);
    }

    return 0;
}
