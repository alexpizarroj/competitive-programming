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

struct Card { char val[3]; };
vector<Card> deck;
inline int CardVal(const Card& c)
{ return ( '2' <= c.val[0] && c.val[0] <= '9' ? c.val[0]-'0' : 10); }

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int n,N,pos,i,k,Y;
    deck.resize(52);

    scanf("%d", &N);
    REP(n,N)
    {
        FOR(i,52) scanf("%s", deck[i].val);
        pos = 26; Y=0;
        REP(i,3)
        {
            Y+= CardVal(deck[pos]);
            k = (10-CardVal(deck[pos]))+1;
            pos -= k;
        }
        k=0;
        FOR(i,52)
        {
            if( i == pos+1 ) i=27;
            k++;
            if( k==Y ) printf("Case %d: %s\n", n, deck[i].val);
        }
    }

    return 0;
}
