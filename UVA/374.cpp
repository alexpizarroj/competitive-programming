#include <stdio.h>

using namespace std;


inline int square(int n) { return n*n; }
int bigmod(int b, int p, int m) {
    if(p == 0) return 1;
    if(p%2==0)
        return square( bigmod(b, p/2, m) ) % m;
    else
        return ( b*bigmod(b, p-1, m) ) % m;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int b, p, m;

    while ( scanf("%d %d %d", &b, &p, &m) != EOF )
        printf("%d\n", bigmod(b%m, p, m));

    return 0;
}
