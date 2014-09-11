#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

static map<char, int> m;


void init() {
    int i, j, k, idx=0, len;
    char *groups = (char*)"333334341", *letters = (char*)"abcdefghijklmnopqrstuvwxyz ";
    //
    len = strlen(groups);
    for(i = 0; i != len; i++) {
        k = groups[i]-'0'; j = 1;
        while (k--)
            m[ letters[idx++] ] = j++;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int T, t=1, i, sum, len;
    char s[101];

    init();
    scanf("%d", &T); getchar();
    while (T--) {
        gets(s);
        len = strlen(s);
        sum = 0;
        for(i = 0; i != len; i++)
            sum += m[ s[i] ];
        printf("Case #%d: %d\n", t++, sum);
    }

    return 0;
}
