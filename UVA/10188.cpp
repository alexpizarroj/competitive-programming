#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#define STRLINELEN 121

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int caseNo = 1, n, m, inlen = STRLINELEN * 99, i, j, k, len;
    char line[STRLINELEN], in1[inlen], in2[inlen], in1num[inlen], in2num[inlen];
    bool newLine;

    while (true) {
        // Entrada
        cin >> n; getchar();
        if(n == 0) break;
        memset(in1, 0, inlen); memset(in2, 0, inlen);
        memset(in1num, 0, inlen); memset(in2num, 0, inlen);
        newLine = false;
        while (n--) {
            memset(line, 0, STRLINELEN);
            gets(line);
            if(newLine) strcat(in1, "\n");
            strcat(in1, line);
            newLine = true;
        }
        cin >> m; getchar();
        newLine = false;
        while (m--) {
            memset(line, 0, STRLINELEN);
            gets(line);
            if(newLine) strcat(in2, "\n");
            strcat(in2, line);
            newLine = true;
        }
        // Resolucion
        if(strcmp(in1,in2)==0) {
            cout << "Run #" << caseNo << ": Accepted" << endl;
        } else {
            len = strlen(in1); k = 0;
            for(i = 0; i < len; i++) {
                j = in1[i]-48;
                if(j > -1 && j < 10) { in1num[k] = in1[i]; k++; }
            }
            len = strlen(in2); k = 0;
            for(i = 0; i < len; i++) {
                j = in2[i]-48;
                if(j > -1 && j < 10) { in2num[k] = in2[i]; k++; }
            }
            cout << "Run #" << caseNo << ": " << (strcmp(in1num, in2num)==0 ? "Presentation Error" : "Wrong Answer") << endl;
        }
        caseNo++;
    }
    return 0;
}
