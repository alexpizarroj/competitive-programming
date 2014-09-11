#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char* str=new char[1024];
    char* last=new char[1024];
    bool lastSet=false, startQuote=false;
    int len, i; char c;

    while (true) {
        gets(str); len=strlen(str);
        if (len==0 || (lastSet && strcmp(str,last)==0)) break;

        for(i=0;i<len;i++) {
            c=str[i];
            if (c!='"') printf("%c", c);
            else {
                startQuote=!startQuote;
                printf("%s", (startQuote ? "``" : "''"));
            }
        }
        printf("\n");

        strcpy(last,str);
        lastSet=true;
    };

    //fclose(stdout);
    return 0;
}
