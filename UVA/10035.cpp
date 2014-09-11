#include <stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int x, y, c=0, i;
    scanf("%d %d", &x, &y);
    while( x || y )
    {
        i = c = 0;
        while( x>0 || y>0 )
        {
            if( (x%10) + (y%10) + c >= 10 )
            {
                i++, c = 1;
            }
            else
            {
                c = 0;
            }
            x /= 10, y /= 10;
        }
        if (i == 0)         puts("No carry operation.");
        else if (i == 1)    puts("1 carry operation.");
        else if (i > 1)     printf("%d carry operations.\n", i);
        scanf("%d %d", &x, &y);
    }
    return 0;
}

// SOLUCION QUE GENERA EL RESULTADO EN UN TERCER VECTOR (tratamiento de cadenas)
// Extrañamente, procesarlo como cadena nos permite obtener un mejor tiempo.
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <memory.h>
using namespace std;

#define MAX 15


int main() {
    freopen("10035.in", "r", stdin); freopen("10035.out", "w", stdout);

    char a[MAX], b[MAX], r[MAX];
    int alen, blen, i, len, num1, num2, cnt;
    bool carry;

    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(r, 0, sizeof r);

    while( scanf("%s %s", a, b) != EOF ) {

        if( strcmp(a,"0") == 0 && strcmp(b,"0") == 0 ) continue;

        alen = strlen(a);
        blen = strlen(b);
        reverse(a, a+alen);
        reverse(b, b+blen);
        len = max(alen, blen);
        cnt = carry = 0;

        for(i=0; i<len; i++) {
            num1 = ( i<alen ? a[i]-'0' : 0 );
            num2 = ( i<blen ? b[i]-'0' : 0 );

            num1 = num1 + num2 + (carry ? 1 : 0);
            carry = (num1 > 9);
            r[i] = (num1%10)+'0';

            if( carry ) cnt++;
        }

        if( cnt == 0 )
            puts("No carry operation.");
        else if ( cnt == 1 )
            puts("1 carry operation.");
        else
            printf("%d carry operations.\n", cnt);

    }

    return 0;
}
*/
