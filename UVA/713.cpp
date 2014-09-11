#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXLEN 220

using namespace std;

static char s1[MAXLEN], s2[MAXLEN], s3[MAXLEN];


void stringrev(char* str) {
    int i = 0, j = strlen(str)-1;
    while (i < j)
        swap(str[i++], str[j--]);
}

char* removeZeroes(char* str) {
    int len = strlen(str), i = 0;
    while ( str[i]=='0' )
        i++;
    len = strlen(str);
    if( len == 0 ) {
        i--;
        len++;
    }
    return &( str[i] );
}

char* add(char* n1, int l1, char* n2, int l2, int* l3) {
    int carry = 0, i = MAXLEN-1;
    int a, b, j1, j2, k;
    char *sp;

    s3[i--] = 0;
    k = max(l1, l2);
    for(j1 = l1-1, j2 = l2-1; k--; j1--, j2--) {
        a = ( !(j1 < 0) ? n1[j1]-'0' : 0);
        b = ( !(j2 < 0) ? n2[j2]-'0' : 0);
        a += b+carry;
        b = a%10;
        carry = (a-b)/10;
        s3[i--] = b+'0';
    }
    if(carry != 0) {
        a = (a-b)/10;
        while ( (b = a%10) != a) {
            s3[i--] = b+'0';
            a = (a-b)/10;
        }
        s3[i--] = b+'0';
    }

    i += 1;
    sp = &( s3[i] );
    sp = removeZeroes(sp);
    *l3 = strlen(sp);

    return sp;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int T, len1, len2, len3, i;
    char *sp;

    scanf("%d", &T);
    while (T--) {
        // Entrada
        scanf("%s %s", s1, s2);
        len1 = strlen(s1);
        len2 = strlen(s2);
        // Resolucion
        stringrev(s1);
        stringrev(s2);
        sp = add(s1, len1, s2, len2, &len3);
        stringrev(sp);
        sp = removeZeroes(sp);
        printf("%s\n", sp);
    }

    return 0;
}
