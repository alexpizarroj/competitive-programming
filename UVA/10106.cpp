#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <list>
#include <sstream>
#include <string>
#include <cstring>

#include <memory.h>
#include <algorithm>
#include <cmath>

#define FORX(i,start,end) for(i=start;i<end;i++)
#define FORY(i,start,end) for(i=start;i<=end;i++)
#define MAX 751

using namespace std;

struct BigNum {
    char n[MAX];
    int nlen, sign;
    BigNum() {
        nlen=0;
        memset(n,0,sizeof(n));
        sign = 1;
    }
    BigNum(char *number) {
        memset(n,0,sizeof(n));
        if(number[0]=='-') {
            strcpy(n, number+1);
            sign = -1;
        } else {
            strcpy(n, number);
            sign = 1;
        }
        nlen = strlen(n);

    }
};

BigNum operator +(BigNum a, BigNum b) {
    if(a.nlen < 1 || b.nlen < 1) return BigNum();

    BigNum c, *bn=&a;
    int k = min(a.nlen, b.nlen), i, carry=0, j;
    if(b.nlen > a.nlen) bn = &b;

    reverse(a.n, a.n+a.nlen);
    reverse(b.n, b.n+b.nlen);
    FORX(i,0,k) {
        j = a.n[i]-'0' + b.n[i]-'0' + carry;
        c.n[i] = (j%10)+'0';
        carry = j/10;
    }
    FORX(i,k,bn->nlen) {
        j = bn->n[i]-'0' + carry;
        c.n[i] = (j%10)+'0';
        carry = j/10;
    }
    while(carry != 0) {
        c.n[i++] = (carry%10)+'0';
        carry /= 10;
    }
    c.n[i] = 0;
    c.nlen = strlen(c.n);

    reverse(c.n, c.n+c.nlen);
    i = 0;
    while(c.n[i]=='0') i++;
    strcpy(c.n, &c.n[i]);
    c.nlen = strlen(c.n);

    return c;
}

BigNum operator *(BigNum a, BigNum b) {
    if(a.nlen < 1 || b.nlen < 1) return BigNum();

    BigNum c, x;
    if(b.nlen > a.nlen) swap(a,b);
    char tmp[2]; int i, j, k, carry=0;
    tmp[1] = 0;

    if(b.nlen==1) {
        if(b.n[0]=='0') return BigNum("0");
        //
        reverse(a.n, a.n+a.nlen);
        k = b.n[0]-'0';
        FORX(i,0,a.nlen) {
            j = (a.n[i]-'0')*k + carry;
            c.n[i] = (j%10)+'0';
            carry = j/10;
        }
        while(carry != 0) {
            c.n[i++] = (carry%10)+'0';
            carry /= 10;
        }
        c.n[i] = 0;
        c.nlen = strlen(c.n);
        reverse(c.n, c.n+c.nlen);

    } else {
        reverse(b.n, b.n+b.nlen);
        k = 1;
        // Primer multiplicacion
        tmp[0] = b.n[0];
        c = a*BigNum(tmp);
        // Sgtes multiplicaciones
        FORX(i,1,b.nlen) {
            tmp[0] = b.n[i];
            x = a*BigNum(tmp);
            FORX(j,0,k) {
                x.n[x.nlen++] = '0';
                x.n[x.nlen] = 0;
            }
            c = c+x;
            k++;
        }
    }

    c.sign = a.sign*b.sign;
    i = 0;
    while(c.n[i]=='0') i++;
    strcpy(c.n, &c.n[i]);
    c.nlen = strlen(c.n);

    return c;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char s1[MAX], s2[MAX];
    while ( gets(s1) != NULL && gets(s2) != NULL ) {
        BigNum a(s1), b(s2);
        a = (a*b);
        if(a.sign==-1) printf("-");
        printf("%s\n", a.n);
    }

    return 0;
}
