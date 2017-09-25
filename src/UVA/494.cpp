#include <stdio.h>
#include <string.h>

using namespace std;

inline bool isLetter(const char c) { return ((c>=65 && c<=90) || (c>=97 && c<=122)); }

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char *str = new char[1024];
    int len, cnt, i; bool contar;
    while (gets(str)) {
        len=strlen(str);
        cnt=0; contar=false;
        for(i=0;i<len;i++) {
            if ( isLetter(str[i]) ) {
                contar=true;
            } else {
                if (contar) cnt++;
                contar=false;
            }
        }
        if(contar) cnt++;
        printf("%d\n", cnt);
    }

    //fclose(stdout);
    return 0;
}
