#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stack>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t, n, i, size;
    char s[129], c, c2;
    stack<char> v;
    bool correct;

    memset(s, 0, 129);
    scanf("%d", &t); getchar();
    while ( t-- ) {
        // Entrada
        gets(s);
        n = strlen(s);
        // Resolucion
        correct = true;
        if(n%2 == 0) {
            if(!n) goto saltoSalida;
            size = 0;
            for(i = 0; i != n; i++) {
                c = s[i];
                switch ( c ) {
                    case '(':
                    case '[':
                        v.push(c);
                        size++;
                        break;
                    case ')':
                    case ']':
                        c2 = (c == ')'  ? '('     : '[');
                        c  = (size != 0 ? v.top() : ' ');
                        if(c != c2) {
                            correct = false;
                            goto saltoSalida;
                        } else {
                            size--;
                            v.pop();
                        }
                        break;
                    default:
                        correct = false;
                        goto saltoSalida;
                }
            }
            if( size != 0 ) correct = false;
        } else
            correct = false;
        // Salida
saltoSalida:
        printf("%s\n", correct ? "Yes" : "No" );
    }

    return 0;
}
