#include <stdio.h>
#include <string.h>

using namespace std;


inline bool isvowel(char c) { return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'); }

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char s1[22], s2[22];
    int n, len1, len2, i;
    bool b1, b2;

    scanf("%d\n", &n);
    while (n--) {
        gets(s1); len1 = strlen(s1);
        gets(s2); len2 = strlen(s2);
        if(len1!=len2) {
            printf("No\n");
            continue;
        }
        for(i = 0; i != len1; i++) {
            b1 = isvowel(s1[i]);
            b2 = isvowel(s2[i]);
            if ( b1==!b2 || ( !b1 && s1[i]!=s2[i] ) ) {
               printf("No\n");
               break;
            }
        }
        if(i == len1) printf("Yes\n");
    }

    return 0;
}
