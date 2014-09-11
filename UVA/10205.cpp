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
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define TOK(pc, s, tokens) for(char* pc = strtok(s, tokens); pc != NULL; pc = strtok(NULL,tokens))
#define PB push_back
#define MP make_pair
#define PI acos(-1)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define range(v) (v).begin(), (v).end()
#define len(a) (int)(a).length()
#define sz(a) (int)(a).size()
#define sqr(a) (a)*(a)
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<double> vd;
typedef vector<dd> vdd;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


#define CARDS_PER_DECK 52
#define CARDS_PER_SUIT 13

const string cards_v[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10",
                          "Jack", "Queen", "King", "Ace"};
const string suits_v[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
void GetCardName(const int cardno, char *out)
{
    int suit  = (cardno-1)/CARDS_PER_SUIT;
    int value = (cardno-1)%CARDS_PER_SUIT;
    strcpy(out, cards_v[value].c_str());
    strcat(out, " of ");
    strcat(out, suits_v[suit].c_str());
}


char line[200];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int t,T,n,readN,k;
    int *deck = new int[CARDS_PER_DECK+1];
    int *tmp  = new int[CARDS_PER_DECK+1];
    vector<vi> sf;

    scanf("%d", &T); getchar();
    getchar();
    FOR(t,T)
    {
        REP(k,CARDS_PER_DECK) deck[k] = k;

        scanf("%d", &n); getchar();
        sf.clear(); readN=0;
        sf.resize(n);
        while( readN < 52*n )
        {
            gets(line);
            TOK(pc, line, " ")
            {
                sscanf(pc, "%d", &k);
                sf[readN/CARDS_PER_DECK].push_back(k);
                readN++;
            }
        }
        while( gets(line) != NULL && strlen(line) > 0 )
        {
            int moveNo;
            sscanf(line, "%d", &moveNo); moveNo--;

            REP(k,CARDS_PER_DECK) tmp[k] = deck[ sf[moveNo][k-1] ];
            swap(deck, tmp);
        }

        if( t ) puts("");
        REP(k,CARDS_PER_DECK)
        {
            GetCardName(deck[k], line);
            printf("%s\n", line );
        }
    }

    return 0;
}
