#include <iostream>
#include <sstream>
#include <stdio.h>
#include <memory.h>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#define UINT unsigned int
#define MAXSTRLEN 12

using namespace std;

static char tmp1[MAXSTRLEN], tmp2[MAXSTRLEN];

inline void u_strrev(char *str, int len)          { reverse(str, str+len);           }
inline void u_toasc (const UINT num, char *ret)   { sprintf(ret, "%u", num);         }
inline UINT u_toint (const char* str) { UINT ret; stringstream ss(str); ss >> ret; return ret; }

bool palindrome(const int num) {
    u_toasc(num, tmp1);
    memcpy(tmp2, tmp1, MAXSTRLEN);
    u_strrev(tmp2, strlen(tmp1));
    return (!strcmp(tmp1, tmp2));
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int caseNo, itcnt;
	UINT a, b;

    memset(tmp1, 0, MAXSTRLEN);
    memset(tmp2, 0, MAXSTRLEN);
	scanf("%d", &caseNo);
	while (caseNo--) {
	    scanf("%u", &a);
        // Resolucion
        itcnt = 0;
        while (!palindrome(a)) {
            u_toasc(a, tmp1);
            u_strrev(tmp1, strlen(tmp1));
            b = u_toint(tmp1);
            a += b;
            itcnt++;
        }
        // Salida
        printf("%d %u\n", itcnt, a);
	}
    return 0;
}
