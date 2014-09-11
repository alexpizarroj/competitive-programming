#include <stdio.h>
#include <algorithm>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    float v1, v2, ans;

    while ( true ) {
        // Entrada
        scanf("%f:%f", &v1, &v2);
        if(v1 == 0 && v2 == 0) break;
        // Resolucion
        v1 = (int)(v1*30)%360 + v2*0.5;
        v2 = (v2*6);
        if(v1 > v2) swap(v1, v2);
        ans = min( v2-v1, v1+360-v2 );
        // Salida
        printf("%.3f\n", ans );
    }

    return 0;
}
