#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int tengo, necesito, i, c=0;
    char str1[255], str2[255], *p;
    memset(str1, 0, 255); memset(str2, 0, 255);
    int data1[13], data2[13];

    while (true) {
        cin >> tengo; getchar();
        if(tengo<0) break; c++;
        gets(str1); gets(str2);
        printf("Case %d:\n", c);
        // Datos
        p=strtok(str1, " "); i=1;
        while(p!=NULL) {
            data1[i] = atoi(p);
            p=strtok(NULL, " "); i++;
        }
        p=strtok(str2, " "); i=1;
        while(p!=NULL) {
            data2[i] = atoi(p);
            p=strtok(NULL, " "); i++;
        }
        // Proceso
        for(i=1;i<=12;i++) {
            necesito = data2[i];
            if(tengo<necesito) {
                cout << "No problem. :(" << endl;
            } else {
                tengo -= necesito;
                cout << "No problem! :D" << endl;
            }
            tengo += data1[i];
        }
    }

    #ifndef ONLINE_JUDGE
        fclose(stdout);
    #endif
    return 0;
}
