#include <stdio.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t, n, m;

    scanf("%d\n", &t);
    while (t--) {
        scanf("%d %d\n", &n, &m);
        printf("%d\n", ((int)n/3)*((int)m/3));
    }

    #ifndef ONLINE_JUDGE
    fclose(stdout);
    #endif
    return 0;
}
