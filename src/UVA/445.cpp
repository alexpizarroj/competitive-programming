#include <stdio.h>
#include <ctype.h>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char row[133], c;
    int i = 0, n = 0, repeat = 0;

    while(  (c = getchar()) != EOF ) {
        if( isdigit(c) ) {
            repeat += c-'0';
        } else if ( c == '\n' && n == 0 ) {
            printf("\n");
        } else if ( c == '!' || c == '\n' ) {
            row[i] = 0;
            printf("%s\n", row);
            n = 0; i = 0;
        } else {
            n += repeat;
            if(c == 'b') c = ' ';
            while ( repeat-- )
                row[i++] = c;
            repeat = 0;
        }
    }
    if(n != 0) {
        row[i] = 0;
        printf("%s\n", row);
        n = 0; i = 0;
    }

    return 0;
}
