#include <cstdio>
#include <algorithm>

using namespace std;
int v[2000005];

int main() {
    int n, i;

    scanf("%d", &n);
    while ( n != 0 ) {
        for(i=0; i<n; i++) scanf("%d", v+i);
        sort(v,v+n);

        printf("%d", v[0]);
        for(i=1; i<n; i++) printf(" %d", v[i]);
        puts("");

        scanf("%d", &n);
    }

    return 0;
}
