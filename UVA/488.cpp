#include <stdio.h>

using namespace std;


static char *v[10] = {"", "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999"};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t, amp, freq;
    int i;
    bool firstDone = false;

    scanf("%d", &t);
    while ( t-- ) {
        scanf("%d %d", &amp, &freq);
        while ( freq-- ) {
            if(firstDone) printf("\n");
            for(i = 1; i <= amp; i++) printf("%s\n", v[i]);
            for(i = amp-1; i >= 1; i--) printf("%s\n", v[i]);
            firstDone = true;
        }
    }

    return 0;
}
