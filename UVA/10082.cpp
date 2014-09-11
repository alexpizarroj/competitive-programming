#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#define ssize 1025

using namespace std;

static string v("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./");


int main() {
    //freopen("input.txt", "r", stdin);

    int len, i, pos;
    char t[ssize];
    memset(t, 0, ssize);

    while (gets(t)) {
        len = strlen(t);
        for(i = 0; i < len; i++) {
            if (t[i] != ' ') t[i] = v.at(v.find(t[i])-1);
        }
        printf("%s\n", t);
        memset(t, 0, len);
    }

    return 0;
}

