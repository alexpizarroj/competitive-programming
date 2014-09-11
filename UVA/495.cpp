#include <stdio.h>
#include <string.h>
#include <algorithm>
#define CPPLIMIT 89
#define REMAINING 5000-CPPLIMIT
#define ULL unsigned long long
#define MAXLEN 1046

using namespace std;


struct FIBNUM { char* num; int len; };

static ULL fib1[CPPLIMIT+1]; // primeros fibos en ULL
static FIBNUM fib2[REMAINING]; // los otros fibos
static char s1[MAXLEN], s2[MAXLEN];

void add(char* n1, int l1, char* n2, int l2, FIBNUM* p) {
    int carry = 0, i = MAXLEN-1;
    int a, b, j1, j2, k;

    p->num = new char[MAXLEN]; p->num[i--] = 0;
    k = max(l1, l2);
    for(j1 = l1-1, j2 = l2-1; k--; j1--, j2--) {
        a = ( !(j1 < 0) ? n1[j1]-'0' : 0);
        b = ( !(j2 < 0) ? n2[j2]-'0' : 0);
        a += b+carry;
        b = a%10;
        carry = (a-b)/10;
        p->num[i--] = b+'0';
    }
    if(carry != 0) {
        a = (a-b)/10;
        while ( (b = a%10) != a) {
            p->num[i--] = b+'0';
            a = (a-b)/10;
        }
        p->num[i--] = b+'0';
    }
    p->num = &( p->num[i+1] );
    p->len = strlen(p->num);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, i;

    // Calcular fibos hasta donde pueda C++
    fib1[0] = 0; fib1[1] = 1;
    for(i = 2; i != 101; i++)
        fib1[i] = fib1[i-1] + fib1[i-2];

    // Calcular fibos de forma manual
    sprintf(s1, "%llu", fib1[CPPLIMIT]); i = strlen(s1);
    sprintf(s2, "%llu", fib1[CPPLIMIT-1]);
    add(s1, i, s2, strlen(s2), &fib2[0]);
    add(s1, i, fib2[0].num, fib2[0].len, &fib2[1]);
    for(i = 2; i != REMAINING; i++)
        add(fib2[i-1].num, fib2[i-1].len, fib2[i-2].num, fib2[i-2].len, &fib2[i]);

    // Proceso de envio de respuestas
    while ( scanf("%d", &n) != EOF ) {
        printf("The Fibonacci number for %d is ", n);
        if(n > CPPLIMIT)
            printf("%s\n", fib2[n-CPPLIMIT-1].num);
        else
            printf("%llu\n", fib1[n]);
    }

    return 0;
}
