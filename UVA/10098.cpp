#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char s[11];
    int n, len;

    scanf("%d\n", &n);
    while (n--) {
        gets(s);
        len = strlen(s);
        sort(s, s+len);
        do {
            printf("%s\n", s);
        } while ( next_permutation(s, s+len) );
        printf("\n");
    }

    return 0;
}
