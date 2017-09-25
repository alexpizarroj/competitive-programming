#include <stdio.h>
#include <string.h>
#include <algorithm>
#define BESTLEN 1048576 // 1 MB

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    bool b;
    char s[BESTLEN], *sp;
    int len, i, j, k;

    while ( gets(s) ) {
        //
        b = false;
        sp = strtok(s, " ");
        while ( sp != NULL ) {
            len = strlen(sp);
            k = (len%2 != 0 ? len-1 : len) / 2;
            if(k != 0) {
                i = 0; j = len-1;
                while (k--) { swap(sp[i], sp[j]);  i++; j--; }
            }

            if(b) printf(" %s", sp); else printf("%s", sp);
            sp = strtok(NULL, " "); b = true;
        }
        printf("\n");
        //
    }

    return 0;
}
