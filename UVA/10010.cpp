#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <memory.h>
#define MAX_STRLEN 21

using namespace std;

static int t, m, n, k, wordcnt, wordlen;
static int i, j, l, l2, o;
static char c1, **v, **v2;
static bool found, firstCaseDone;
static char tmp[MAX_STRLEN];

inline void str_tolower(char* str, int len) { for(int i = 0; i < len; i++) str[i] = tolower(str[i]); }

inline bool has(const int x, const int y) { return !(x<1 || y<1 || x > n || y > m); }

bool getstr(int x1, int y1, int x2, int y2, int sumx, int sumy) {
    if(has(x2,y2)) {
        l = x1-1; l2 = y1-1;
        for(o = 0; o < wordlen; o++) {  tmp[o] = v[l2][l];  l += sumx; l2 += sumy;  }
        tmp[o] = 0;
        return true;
    }
    return false;
}

bool check(int x, int y, const char* s) {
    int f = wordlen-1;
    // 1: horinzontal-right
    if( getstr(x, y, x+f, y, 1, 0) )        if(strcmp(s, tmp)==0) return true;
    // 2: horinzontal-left
    if( getstr(x, y, x-f, y, -1, 0) )       if(strcmp(s, tmp)==0) return true;
    // 3: vertical-down
    if( getstr(x, y, x, y+f, 0, 1) )        if(strcmp(s, tmp)==0) return true;
    // 4: vertical-up
    if( getstr(x, y, x, y-f, 0, -1) )       if(strcmp(s, tmp)==0) return true;
    // 5: diagonal-(from bottom left to top right)
    if( getstr(x, y, x+f, y-f, 1, -1) )     if(strcmp(s, tmp)==0) return true;
    // 6: diagonal-(from top right to bottom left)
    if( getstr(x, y, x-f, y+f, -1, 1) )     if(strcmp(s, tmp)==0) return true;
    // 7: diagonal-(from bottom right to top left)
    if( getstr(x, y, x-f, y-f, -1, -1) )    if(strcmp(s, tmp)==0) return true;
    // 8: diagonal-(from top left to bottom right)
    if( getstr(x, y, x+f, y+f, 1, 1) )      if(strcmp(s, tmp)==0) return true;
    // else:
    return false;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    firstCaseDone = false;
    scanf("%d\n", &t);
    while(t--) {
        // Entrada
        scanf("%d %d\n", &m, &n);
        v = new char*[m];
        for(i = 0; i < m; i++) {
            v[i] = new char[n+1]; gets(v[i]);
            str_tolower(v[i], n);;
        }
        scanf("%d\n", &k);
        v2 = new char*[k];
        for(i = 0; i < k; i++) {
            v2[i] = new char[MAX_STRLEN]; gets(v2[i]);
            str_tolower(v2[i], strlen(v2[i]));
        }
        // Salida
        if(firstCaseDone) printf("\n");
        for(wordcnt = 0; wordcnt < k; wordcnt++) {
            found = false;
            c1 = v2[wordcnt][0];
            wordlen = strlen(v2[wordcnt]);
            for(i = 0; i < m; i++) {
                for(j = 0; j < n; j++) {
                     if(c1 == v[i][j]) {
                         // Resolución
                         if(check(j+1, i+1, v2[wordcnt])) {
                            printf("%d %d\n", i+1, j+1);
                            found = true; break;
                         }
                     }
                }
                if(found) break;
            }
        }
        firstCaseDone = true;
    }


    return 0;
}
