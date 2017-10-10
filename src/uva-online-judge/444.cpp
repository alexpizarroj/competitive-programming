#include <iostream>
#include <sstream>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <algorithm>
#define MAXSTRLEN 241

using namespace std;


char* u_strrev(const char* str, int len) {
    if(len < 0) len = strlen(str);
    char* ret = new char[len+1];
    strcpy(ret, str);
    reverse(ret, ret+len);
    return ret;
}

char* u_toasc(int num) {
    char* ret = new char[11];
    sprintf(ret, "%d", num);
    return ret;
}

int u_toint(const char* str) {
    int ret;
    stringstream ss(str);
    ss >> ret;
    return ret;
}

bool u_valid(const int c) {
    return ( (c > 64 && c < 91) ||  (c > 96 && c < 123) || c == 32 || c == 33 || c == 44 || c == 46 || c == 58 || c == 59 || c == 63 );
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int i, j, k, l, len;
    char s[MAXSTRLEN], ret[MAXSTRLEN], buffer[4];
    memset(s, 0, MAXSTRLEN);

    while (gets(s) != NULL)  {
        len = strlen(s);
        memset(ret, 0, MAXSTRLEN);
        // Decodificar
        if (s[0] >= 48 && s[0] <= 57) {
            j = 3; l = 0;
            for(i = len - 1; i > -1; i--) {
                if (j == 3) {
                    memset(buffer, 0, 4);
                    j = 0;
                }
                buffer[j] = s[i];
                j++;
                if(j == 3 || i == 0) {
                    k = u_toint(buffer);
                    if(!u_valid(k)) { i++; buffer[2] = '\0'; k = u_toint(buffer);}
                    ret[l] = (char)k;
                    l++;
                }
            }
        } else {
            // Codificar
            for(i = len - 1; i > -1; i--) {
                strcat(ret, u_strrev(u_toasc((int)s[i]), -1));
            }
        }
        cout << ret << endl;
    }

    return 0;
}
