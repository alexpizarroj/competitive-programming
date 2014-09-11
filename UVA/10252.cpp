#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <algorithm>
#define MAX_STRLEN 1001
#define MAX_LEN 26

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);

    char s1[MAX_STRLEN], s2[MAX_STRLEN];
    int v1[MAX_LEN], v2[MAX_LEN], i;

    while (true) {
        // Entrada
        memset(s1, 0, MAX_STRLEN);
        memset(s2, 0, MAX_STRLEN);
        memset(v1, 0, sizeof(int)*MAX_LEN);
        memset(v2, 0, sizeof(int)*MAX_LEN);
        if(!gets(s1) || !gets(s2)) break;
        // Resolucion
        for(i = 0; s1[i] != '\0'; i++) v1[(int)(s1[i]-97)]++;
        for(i = 0; s2[i] != '\0'; i++) v2[(int)(s2[i]-97)]++;
        memset(s1, 0, MAX_STRLEN);
        for(i = 0; i < MAX_LEN; i++) strcat(s1, string(min(v1[i], v2[i]), (char)97+i).c_str());
        sort(s1, s1+strlen(s1));
        // Salida
        cout << s1 << endl;
    }

    return 0;
}

