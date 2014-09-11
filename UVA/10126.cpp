#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#define BUFFER 250000
#define MAXWORDS 10000
#define EMPTYCHAR 0

using namespace std;

struct WORD { char *text; int len, repeats; };
static WORD words[MAXWORDS];
static int wordCnt;
static char s[BUFFER+1];


inline int cmpWord(WORD *a, WORD *b) { return strcmp(a->text, b->text); }

int getIndex(char *word, int len) {
    int first = 0, last = wordCnt-1, mid, ret;
    while ( first <= last ) {
        mid = (first+last)/2;
        ret = strcmp(word, words[mid].text);
        if(ret < 0)
            last = mid-1;
        else if ( ret > 0)
            first = mid+1;
        else
            return mid;
    }
    return -1;
}

void add(char *word, int len) {
    int i;
    // Agregar
    words[wordCnt].text = new char[len+1];
    strcpy( words[wordCnt].text, word );
    words[wordCnt].len = len;
    words[wordCnt].repeats = 1;
    wordCnt++;
    // Ordenar
    for(i = wordCnt-1; i != 0; i--) {
        if( strcmp(words[i].text, words[i-1].text) < 0 )
            swap(words[i], words[i-1]);
        else
            break;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, n2, reqCnt;
    int i, j;
    bool firstDone = false;
    char *sp;

    while ( scanf("%d", &reqCnt) != EOF ) {
        getchar();
        wordCnt = 0;
        while ( true ) {
            // Entrada
            gets(s);
            if( strcmp(s, "EndOfText") == 0 ) break;
            n = strlen(s);
            // Normalizar
            j = 0;
            for(i = 0; i != n; i++) {
                if( !isalpha(s[i]) ) {
                    s[i] = EMPTYCHAR;
                    if(j == 1)
                        s[i-1] = EMPTYCHAR;
                    j = 0;
                } else {
                    s[i] = tolower(s[i]);
                    j++;
                }
            }
            // Conteo
            i = 0;
            while( i != n ) {
                if( s[i] != EMPTYCHAR ) {
                    sp = &(s[i]);
                    n2 = strlen(sp);
                    if( (j = getIndex(sp, n2)) == -1 )
                        add(sp, n2);
                    else
                        words[j].repeats++;
                    i += n2;
                } else
                    i++;
            }
        }
        // Salidas
        if(firstDone) printf("\n");
        j = 0;
        for(i = 0; i != wordCnt; i++)
            if( words[i].repeats == reqCnt ) {
                printf("%s\n", words[i].text);
                j++;
            }
        if(!j)
            printf("There is no such word.\n");
        firstDone = true;
    }

    return 0;
}
