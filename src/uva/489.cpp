#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define set(a,v) memset(a, v, sizeof(a))
#define len(a) (int)(a.length())


#define WIN 2
#define LOSE 1
#define CHICKENED 0
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int round, i, j, sticks, done;
    string word, guesses;
    set<char> correct, wrong;
    vector<bool> v;
    int result;

    scanf("%d", &round); getchar();
    while( round != -1 )
    {
        getline(cin,word);
        getline(cin,guesses);

        correct.clear();
        wrong.clear();
        sticks = done = 0;
        result = CHICKENED;

        FOR(i,len(guesses))
        {
            char &c = guesses[i];
            if( word.find(c) == string::npos )
            {
                if( !wrong.count(c) )
                {
                    wrong.insert(c);
                    sticks++;
                    if( sticks == 7 ) { result = LOSE; break; }
                }
            }
            else
            {
                if( !correct.count(c) )
                {
                    correct.insert(c);
                    FOR(j,len(word)) if( word[j]==c ) done++;
                    if( done == len(word) ) { result = WIN; break; }
                }
            }
        }

        printf("Round %d\n", round);
        if( result == WIN )
            puts("You win.");
        else if ( result == LOSE )
            puts("You lose.");
        else
            puts("You chickened out.");

        scanf("%d", &round); getchar();
    }

    return 0;
}
