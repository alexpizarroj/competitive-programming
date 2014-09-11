#include <stdio.h>
#include <algorithm>
#define BESTLEN 101

using namespace std;

struct ITEM {
    ITEM() { web = new char[BESTLEN]; }
    char* web; int value;
};

bool cmpITEM(ITEM a, ITEM b) { return a.value > b.value; }


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int T, t, i, j;
    ITEM v[10];

    scanf("%d\n", &T); T++;
    for (t = 1; t != T; t++) {
        // Entrada y solucion
        for(i = 0; i != 10; i++) scanf("%s %d", v[i].web, &v[i].value);
        stable_sort(v, v+10, cmpITEM);
        j = v[0].value;
        // Salida
        printf("Case #%d:\n", t);
        for(i = 0; i != 10; i++) {
            if (v[i].value != j) break;
            printf("%s\n", v[i].web);
        }
    }

    return 0;
}
