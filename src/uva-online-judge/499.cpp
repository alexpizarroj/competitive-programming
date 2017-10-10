#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

inline bool isLetter(char c) { return ((c>=65 && c<=90) || (c>=97 && c<=122)); }


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int f[123], f2[123];
    char *str = new char[1024], c;
    int len, i, max;
    vector<char> v;

    while (gets(str)) {
        memset(f,0,sizeof(int)*123); v.clear();
        len=strlen(str);
        sort(str,str+len);
        for(i=0;i<len;i++) if (isLetter(str[i])) f[(int)str[i]]++;
        memcpy(f2,f,sizeof(int)*123);
        sort(f2,f2+123); max=f2[122];
        for(c=1;c<123;c++) if(f[(int)c]==max) v.push_back(c);
        sort(v.begin(), v.end());

        for(i=0;i<(int)v.size();i++) printf("%c", v.at(i));
        printf(" %d\n", max);
    }

    //fclose(stdout);
    return 0;
}
