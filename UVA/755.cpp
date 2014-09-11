// IO
#include <iostream>
#include <cstdio>
// STL
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;
// STRINGS
#include <string>
#include <cstring>
// OTROS
#include <cstdlib>
#include <memory.h>
#include <cmath>
// MACROS
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()


struct tNumber
{
    tNumber(const char *_text, const int _cnt)
    {
        strcpy(text, _text);
        cnt = _cnt;
    }
    char text[9];
    int cnt;
};
bool operator <(tNumber a, tNumber b) { return strcmp(a.text, b.text) < 0; }

map<char,short> m;
map<int,int> numbers;
map<int,int>::iterator it;
set<tNumber> s; set<tNumber>::iterator sit;

inline int toStd(const char *n)
{
    int val = 0, len = strlen(n), i, x;

    for(i=0; i<len; i++)
    {
        const char &c = n[i];

        if( c == '-' ) continue;
        if( c >= '0' && c <= '9' )
            x = c-'0';
        else
            x = m[c];

        val = val*10 + x;
    }

    return val;
}

inline void toStd(const int n, char *celphone)
{
    char aux[9];

    sprintf(aux, "%07d", n);
    strcpy(celphone, aux);
    celphone[3] = '-'; celphone[4] = 0;
    strcat(celphone, aux+3 );
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int T, n, i;
    bool firstcase = true;
    char buffer[101];

    m['A'] = m['B'] = m['C'] = 2;
    m['D'] = m['E'] = m['F'] = 3;
    m['G'] = m['H'] = m['I'] = 4;
    m['J'] = m['K'] = m['L'] = 5;
    m['M'] = m['N'] = m['O'] = 6;
    m['P'] = m['R'] = m['S'] = 7;
    m['T'] = m['U'] = m['V'] = 8;
    m['W'] = m['X'] = m['Y'] = 9;
    scanf("%d", &T); getchar();

    while( T-- )
    {
        numbers.clear();
        s.clear();

        getchar();
        scanf("%d", &n); getchar();
        for(i=0;i<n;i++)
        {
            gets(buffer);
            numbers[ toStd(buffer) ]++;
        }

        if(!firstcase) puts("");

        for(it=numbers.begin(); it!=numbers.end(); it++)
            if( it->second > 1 )
            {
                char celphone[10];
                toStd(it->first, celphone);
                s.insert( tNumber(celphone, it->second) );
            }

        if( s.size() == 0 )
            puts("No duplicates.");
        else
        {
            for(sit=s.begin(); sit!=s.end(); sit++)
                printf("%s %d\n", sit->text, sit->cnt);
        }

        firstcase = false;
    }

    return 0;
}
