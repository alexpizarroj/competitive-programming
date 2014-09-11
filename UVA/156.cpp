#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <vector>

using namespace std;

struct ITEM {  char *word, *normalizedWord; int len;  };


char* normalize(const char* str, const int len) {
    int i; char *ret = new char[len+1];

    memcpy(ret, str, len+1);
    for(i = 0; i != len; i++)
        ret[i] = tolower(ret[i]);
    sort(ret, ret+len);

    return ret;
}

bool cmp(ITEM a, ITEM b) {  return strcmp(a.word, b.word) < 0;  }

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char* inputstr, *word;
    vector<ITEM> v; ITEM *pitem;
    vector<ITEM>::iterator it, it2;
    bool duplicated;

    // Entrada
    while ( true ) {
        inputstr = new char[81];
        gets(inputstr);
        if( inputstr[0] == '#' && inputstr[1] == 0 ) break;
        word = strtok(inputstr, " ");
        while ( word != NULL ) {
            pitem = new ITEM();
            pitem->len = strlen(word);
            pitem->word = word;
            pitem->normalizedWord = normalize(pitem->word, pitem->len);
            v.push_back(*pitem);
            word = strtok(NULL, " ");
        }
    }
    // Resolucion
    it = v.begin();
    while ( it != v.end() ) {
        duplicated = false;
        it2 = it+1;
        while ( it2 != v.end() ) {
            if ( strcmp( (*it).normalizedWord, (*it2).normalizedWord ) == 0 ) {
                duplicated = true;
                it2 = v.erase(it2);
            } else
                it2++;
        }
        if(duplicated)
            it = v.erase(it);
        else
            it++;
    }
    sort(v.begin(), v.end(), cmp);
    // Salida
    for(it = v.begin(); it != v.end(); it++) {
        printf("%s\n", (*it).word );
    }

    return 0;
}
