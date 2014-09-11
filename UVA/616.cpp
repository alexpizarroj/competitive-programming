#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, ans;
    int i, j, k, lim;
    bool wrong;

    while ( true ) {
        // Entrada
        scanf("%d", &n);
        if(n < 0) break;
        // Resolucion
        ans = 0;
        if(n != 0) {
            lim = sqrt(n-1)+1;;
            for(j = lim; j != 1; j--) {
                i = j; k = n;
                wrong = false;
                while (!wrong && i--) {
                    k--;
                    if( k%j != 0 ) wrong=true;
                    else k -= k/j;
                }
                if(!wrong)
                    if( k%j != 0 ) wrong = true;
                if(!wrong) {
                    ans = j;
                    break;
                }
            }
        }
        // Salida
        if(ans)
            printf("%d coconuts, %d people and 1 monkey\n", n, ans);
        else
            printf("%d coconuts, no solution\n", n);
    }

    return 0;
}
