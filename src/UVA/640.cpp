#include <stdio.h>
#include <memory.h>
#define MAX 1000000

using namespace std;

static bool v[MAX+1];


// Digitation
int dgt(int n) {
    int ans = n;
    while (n != 0) {
        ans += n%10;
        n /= 10;
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int i, k;
    memset(v, true, sizeof(bool)*MAX+1);

    for(i = 1; i <= MAX; i++) {
        k = dgt(i);
        if( k <= MAX) v[k] = false;
    }
    for(i = 1; i <= MAX; i++)
        if( v[i] ) printf("%d\n", i);

    return 0;
}
