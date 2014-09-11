#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <list>
#include <sstream>
#include <string>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define FOR(i,n) for(i=0;i<n;i++)
#define REP(i,n) for(i=1;i<=n;i++)
#define PB push_back
#define MP make_pair
#define ALL(v) v.begin(), v.end()
using namespace std;

#define CARDS 13
#define SUITS 4
map<char, int> suitValue;
struct SUIT {
    char suit;
    int a, k, q, j;
    int totalCards;
    bool stopped;

    void clean() {
        stopped = false;
        a = k = q = j = 0;
        totalCards = 0;
    }

    void updateStopped() {
        stopped = (a > 0 || (k > 0 && totalCards > 1) || (q > 0 && totalCards > 2));
    }
};
bool cmp(SUIT a, SUIT b) {
    if( a.totalCards != b.totalCards ) return a.totalCards > b.totalCards;
    return suitValue[a.suit] < suitValue[b.suit];
}


int main() {
    #ifndef ONLINE_JUDGE
	freopen("marco.in", "r", stdin);
    #endif

    char cards[CARDS][3], suit;
    SUIT suits[SUITS];
    int i, j, ret;
    int points1, points2;
    bool allStopped;

    suits[0].suit = 'S';
    suits[1].suit = 'H';
    suits[2].suit = 'D';
    suits[3].suit = 'C';
    suitValue['S'] = 0;
    suitValue['H'] = 1;
    suitValue['D'] = 2;
    suitValue['C'] = 3;

    while ( true ) {

        FOR(i,CARDS) ret = scanf("%s", cards[i]);
        if ( ret == EOF ) break;

        FOR(i,SUITS) {
            suits[i].clean();
            suit = suits[i].suit;
            FOR(j,CARDS) {
                if( cards[j][1] != suit ) continue;
                switch (cards[j][0]) {
                    case 'A':
                        suits[i].a++;
                        break;
                    case 'K':
                        suits[i].k++;
                        break;
                    case 'Q':
                        suits[i].q++;
                        break;
                    case 'J':
                        suits[i].j++;
                        break;
                }
                suits[i].totalCards++;
            }
            suits[i].updateStopped();
        }
        sort(suits, suits+SUITS, cmp);

        points1 = 0;
        FOR(i,SUITS) {
            points1 += suits[i].a*4;
            points1 += suits[i].k*3;
            points1 += suits[i].q*2;
            points1 += suits[i].j;
            if( suits[i].k > 0 && suits[i].totalCards <= 1 ) points1 -= suits[i].k;
            if( suits[i].q > 0 && suits[i].totalCards <= 2 ) points1 -= suits[i].q;
            if( suits[i].j > 0 && suits[i].totalCards <= 3 ) points1 -= suits[i].j;
        }

        points2 = points1;
        FOR(i,SUITS) {
            if( suits[i].totalCards == 2 ) points2 += 1;
            if( suits[i].totalCards < 2 )  points2 += 2;
        }

        allStopped = true;
        FOR(i,SUITS) {
            if( !suits[i].stopped ) {
                allStopped = false;
                break;
            }
        }

        if( points1 >= 16 && allStopped )
            puts("BID NO-TRUMP");
        else if ( points2 >= 14 )
            printf("BID %c\n", suits[0].suit);
        else
            puts("PASS");

    }

    return 0;
}
