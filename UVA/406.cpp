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
#define MAXN 1000
#define MAXN_SQRT 32

using namespace std;

static bool prime[MAXN+1];
static int primes[MAXN+1];

int initPrimes() {
    // Mark primes
    int i, j;
    memset(prime, true, MAXN);
    prime[0] = false; prime[1] = true;
    for(i = 4; i <= MAXN; i += 2) prime[i] = 0;
    for(i = 3; i <= MAXN_SQRT; i += 2) {
        if( prime[i] ) {
            for(j = i*i; j <= MAXN; j += i) prime[j] = 0;
        }
    }
    // List primes
    for(i = 1, j = 1; i <= MAXN; i++)
        if( prime[i] ) primes[j++] = i;
    // Show them
    /*
    printf("Primos:");
    for(i = 1; i < j; i++) printf(" %d", primes[i]);
    printf("\n");
    */

    return j-1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, c, i, k, left, right, nprimes = initPrimes(), nlist;

    while ( scanf("%d %d", &n, &c) != EOF ) {
        // Calcular lista
        nlist = 1;
        while ( n >= primes[nlist] && nlist <= nprimes) nlist++;
        nlist--;
        k = (nlist%2==0 ? c*2 : (c*2)-1);
        if(k >= nlist) {
            left = 1;
            right = nlist;
        } else {
            left = (nlist-k)/2+1;
            right = left+k-1;
        }
        // Salida
        printf("%d %d:", n, c);
        for(i = left; i <= right; i++)
            printf(" %d", primes[i]);
        printf("\n\n");
    }

    return 0;
}
