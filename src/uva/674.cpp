#include <stdio.h>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#define MAXC 7489
#define NCOINS 5
#define int64 unsigned long long

using namespace std;

static int64 nways[MAXC+1];
static int coins[NCOINS] = {50, 25, 10, 5, 1};


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int i, j, n, c;

    nways[0] = 1;
    for(i=1; i<=MAXC; i++) nways[i] = 0;
    for(i=0; i<NCOINS; i++) {
        c = coins[i];
        for(j=c; j<=MAXC; j++) nways[j] += nways[j-c];
    }
    while ( scanf("%d", &n) != EOF ) printf("%llu\n", nways[n]);

    return 0;
}
