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


int main() {
    //freopen("data.in", "r", stdin);

    typedef map< string, set<string> >  tMap;
    typedef tMap::iterator              tMapIt;

    tMap dic; tMapIt it;
    string word, sortedWord;
    set<string>::iterator stIt;

    getline(cin, word);
    do {
        sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        if( dic.count(sortedWord) == 0 )
        {
            set<string> st;
            st.insert(word);
            dic.insert( make_pair(sortedWord, st) );
        }
        else
        {
            dic[sortedWord].insert( word );
        }

        getline(cin, word);
    } while( word != "XXXXXX" );

    getline(cin, word);
    do {
        sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());

        if( dic.count(sortedWord) == 0 )
            puts("NOT A VALID WORD");
        else
        {
            set<string> &st = dic[sortedWord];
            for(stIt = st.begin(); stIt != st.end(); stIt++)
                cout << *stIt << endl;
        }
        puts("******");

        getline(cin, word);
    } while( word != "XXXXXX" );

    return 0;
}
