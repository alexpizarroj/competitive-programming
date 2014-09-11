#include <stdio.h>
#include <math.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    double n, p;
    while ( scanf("%lf %lf", &n, &p) != EOF )
        printf("%.0lf\n",  pow(p, 1.0/n) );

    return 0;
}
