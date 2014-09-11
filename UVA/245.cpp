#include <stdio.h>
#include <sstream>
#include <memory.h>
#include <string.h>
#include <list>
#define BUFFERSIZE 50050 // para un maximo de 50 palabras (de 50 chars) separadas por espacio
#define BESTWORDLEN 51

using namespace std;

inline int toint(const char* str) { int ret; stringstream ss(str); ss >> ret; return ret; }

static char s[BUFFERSIZE], *word;
static int slen, i, k, wordlen;
static list<char*> lst;
static list<char*>::iterator lstit;


void translate() {
    k = ( ( word[0] >= '0' && word[0] <= '9' ) ? toint(word) : 0) - 1;
    if( k == -1 ) {
        printf("%s", word);
        lst.push_front(word);
    } else {
        lstit = lst.begin(); while ( k-- ) lstit++;
        printf("%s", *lstit);
        lst.remove(*lstit); lst.push_front(*lstit);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    memset(s, 0, BUFFERSIZE);
    while ( true ) {
        // Entrada
        gets(s);
        if( s[0] == '0' ) break;
        slen = strlen(s);
        // Resolucion parcial, salida parcial
        word = new char[BESTWORDLEN]; wordlen = 0;
        for(i = 0; i != slen; i++) {
            if( isalpha(s[i]) ||isdigit(s[i]) ) word[wordlen++] = s[i];
            else {
                if( wordlen != 0) {
                    word[wordlen] = 0;
                    translate();
                    word = new char[BESTWORDLEN]; wordlen = 0;
                }
                printf("%c", s[i]);
            }
        }
        if( wordlen != 0) {
            word[wordlen] = 0;
            translate();
        }
        printf("\n");
    }


    return 0;
}
