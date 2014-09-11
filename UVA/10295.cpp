#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;


struct WORD {  char text[17];  float value;  };
static WORD dic[1000];
static int dicLen;
static char s[1001];


float getValue(char* word) {
    int first = 0, last = dicLen-1, mid, ret;
    while (first <= last) {
        mid = (first+last)/2;
        ret = strcmp(word, dic[mid].text);
        if(ret < 0)
            last = mid-1;
        else if (ret > 0)
            first = mid+1;
        else
            return dic[mid].value;
    }
    return 0.;
}

bool cmpWord(WORD a, WORD b) { return strcmp(a.text, b.text) < 0 ; }

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int m, n, i, len;
    float salary;
    char *sp;

    while ( scanf("%d %d", &m, &n) != EOF ) {
        getchar();
        for(i = 0; i != m; i++) {
            gets(s);
            sscanf(s, "%s %f", dic[i].text, &dic[i].value);
        }
        sort(dic, dic+m, cmpWord);
        dicLen = m;
        while( n-- ) {
            salary = 0.;
            while ( true ) {
                gets(s);
                len = strlen(s);
                if( len == 1 && s[0] == '.') break;
                sp = strtok(s, " ");
                while (sp != NULL) {
                    salary += getValue(sp);
                    sp = strtok(NULL, " ");
                }
            }
            printf("%.f\n", salary);
        }
    }
    return 0;
}
