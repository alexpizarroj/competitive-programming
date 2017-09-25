#include <stdio.h>

using namespace std;


int f91(int n) {
    if(n <= 100)
        return f91(f91(n+11));
    else
        return n-10;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n;

    while ( scanf("%d", &n) && n )
        printf("f91(%d) = %d\n", n, f91(n));

    return 0;
}
