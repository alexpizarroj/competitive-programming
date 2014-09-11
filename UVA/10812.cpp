#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, a[2], b[2], sum, diff, i;
    float d;

    scanf("%d", &n);
    while (n--) {
        // Entrada
        scanf("%d %d", &sum, &diff);
        // Resolucion
        d = ( pow(sum, 2) - 4*( (pow(sum,2) - pow(diff, 2))/4 ) ); // Discriminante
        if(d >= 0) {
            d = pow(d, 0.5);
            if( trunc(d) == d ) {
                if ( (int)(sum+d)%2==0 ) {
                    b[0] = (sum + d) / 2;
                    a[0] = sum - b[0];
                } else {
                    b[0] = -1;
                    a[0] = -1;
                }
                if ( (int)(sum-d)%2==0 ) {
                    b[1] = (sum - d) / 2;
                    a[1] = sum - b[0];
                } else {
                    b[1] = -1;
                    a[1] = -1;
                }
                if ( a[0] >= 0 && b[0] >= 0)
                    i = 0;
                else if ( a[1] >= 0 && b[1] >= 0)
                    i = 1;
                else
                    i = -1;
            } else
                i = -1;
        } else
            i = -1;
        // Salida
        if(i == -1)
            printf("impossible\n");
        else {
            if( a[i] < b[i] ) swap(a[i], b[i]);
            printf("%d %d\n", a[i], b[i]);
        }
    }

    return 0;
}

