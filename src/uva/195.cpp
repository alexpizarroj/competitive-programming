#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#define BESTLEN 5001

using namespace std;


static float x, y;
bool cmp(char a, char b) {
    x = a - ( islower(a) ? 31.5 : 0);
    y = b - ( islower(b) ? 31.5 : 0);
    return x < y;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, len;
    char s[BESTLEN];

    scanf("%d\n", &n);
    while (n--) {
        gets(s);
        len = strlen(s);
        sort(s, s+len, cmp);
        do {
            printf("%s\n", s);
        } while ( next_permutation(s, s+len, cmp) );
    }

    return 0;
}

