#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <memory.h>
#define MAXLEN 150

using namespace std;

struct LONGNUM { char* num; int len; };
static char *v[100], *tmp;


char* add(char *n1, char *n2) {
    int a, b, j1, j2, k;
    int carry = 0, i = MAXLEN-2;
    int l1 = strlen(n1), l2 = strlen(n2);
    char *result = new char[MAXLEN];
    result[MAXLEN-1] = 0;

    k = max(l1, l2);
    for(j1 = l1-1, j2 = l2-1; k--; j1--, j2--) {
        a = ( !(j1 < 0) ? n1[j1]-'0' : 0);
        b = ( !(j2 < 0) ? n2[j2]-'0' : 0);
        a += b+carry;
        b = a%10;
        carry = (a-b)/10;
        result[i--] = b+'0';
    }
    if(carry != 0) {
        a = (a-b)/10;
        while ( (b = a%10) != a) {
            result[i--] = b+'0';
            a = (a-b)/10;
        }
        result[i--] = b+'0';
    }
    result = result+i+1;

    return result;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n = 0, i;

    // Entrada
    while( true ) {
        tmp = new char[MAXLEN]; gets(tmp);
        if( tmp[0] == '0' && tmp[1] == 0)
            break;
        else
            v[n++] = tmp;
    }
    // Resolucion
    for(i = 1; i != n; i++)
        v[i] = add( v[i-1], v[i] );
    // Salida
    printf("%s\n", v[--i]);

    return 0;
}
