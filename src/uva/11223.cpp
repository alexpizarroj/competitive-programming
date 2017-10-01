#include <stdio.h>
#include <string.h>
#include <memory.h>
#define BESTLEN 2001
#define ITEMCNT 53
#define TOKENCHAR '`'
#define TOKENSTR "`"

using namespace std;

struct ITEM {
    ITEM(char pkey, char *pvalue) : key(pkey), value(pvalue) {}
    char key, *value;
};
inline ITEM* c(char a, char* b) { return new ITEM(a, b); }

static ITEM *m[ITEMCNT] = {
                       c('T', "-"), c('M', "--"), c('O', "---"), c('0', "-----"), c('9', "----."), c('8', "---.."),
                       c(':', "---..."), c('G', "--."), c('Q', "--.-"), c('Z', "--.."), c(',', "--..--"),
                       c('7', "--..."), c('N', "-."), c('K', "-.-"), c('Y', "-.--"), c('(', "-.--."),
                       c(')', "-.--.-"), c('C', "-.-."), c('!', "-.-.--"), c(';', "-.-.-."), c('D', "-.."),
                       c('X', "-..-"), c('/', "-..-."), c('B', "-..."), c('=', "-...-"), c('6', "-...."),
                       c('-', "-....-"), c('E', "."), c('A', ".-"), c('W', ".--"), c('J', ".---"),
                       c('1', ".----"), c('\'', ".----."), c('P', ".--."), c('@', ".--.-."), c('R', ".-."),
                       c('+', ".-.-."), c('.', ".-.-.-"), c('L', ".-.."), c('"', ".-..-."), c('&', ".-..."),
                       c('I', ".."), c('U', "..-"), c('2', "..---"), c('_', "..--.-"), c('?', "..--.."),
                       c('F', "..-."), c('S', "..."), c('V', "...-"), c('3', "...--"), c('H', "...."),
                       c('4', "....-"), c('5', ".....")
                     };


char get(const char* key) {
    int first = 0, last=ITEMCNT-1, mid; char *s;

    while ( first <= last )  {
        mid = first + (last-first)/ 2;
        s = (*m[mid]).value;
        if( strcmp(key, s) == 0 ) {
            return (*m[mid]).key;
        } else if ( strcmp(key, s) < 0 ) {
            last = mid-1;
        } else {
            first = mid+1;
        }
    }

    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char s[BESTLEN], *p, ch;
    int c, C, i, len;
    bool first = false, changed;
    memset(s, 0, BESTLEN);

    scanf("%d\n", &C); C++;
    for(c = 1; c != C; c++) {
        if(first) printf("\n");
        printf("Message #%d\n", c);
        gets(s); len = strlen(s);
        changed = false;
        for(i = 0; i != len; i++) {
            if( s[i]==' ' && !changed ) {
                changed = true;
                s[i] = TOKENCHAR;
            } else changed = false;
        }
        //
        p = strtok(s, TOKENSTR);
        while (p != NULL) {
            i = 0;
            while( p[i] == ' ' ) { printf(" "); i++; }
            p = &p[i];
            ch = get(p); if(ch) printf("%c", ch);
            p = strtok(NULL, TOKENSTR);
        }
        printf("\n");
        first = true;
    }

    return 0;
}
