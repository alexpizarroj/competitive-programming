#include <stdio.h>

using namespace std;


int main() {
    int i, a, b, c, r;
    while (scanf("%d %d %d %d",&i,&a,&b,&c)==4) {
        if (!i && !a && !b && !c) break;
        r = 1080 + (((a>i?(40-a)+i:(i-a)) + (b<a?(40-a)+b:(b-a)) + (c>b?(40-c)+b:(b-c))))*9;
        printf("%d\n",r);
    }
    return 0;
}
