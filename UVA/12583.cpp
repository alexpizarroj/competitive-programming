// includes {
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
// }
using namespace std;
// defines {
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define TOK(pc, s, tokens) for(char* pc = strtok(s, tokens); pc != NULL; pc = strtok(NULL,tokens))
#define SZ(a) (int)(a).size()
#define LEN(a) (int)(a).length()
#define PB push_back
#define MP make_pair
#define all(a) (a).begin(), (a).end()
#define sqr(a) (a)*(a)
#define inrange(lb,i,ub) ((lb) <= (i) && (i) <= (ub))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// }
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};


#define NEVER -1000
const int alphabetSize = 'Z'-'A'+1;
int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	int n, k, tc, T, i, len, recognizedCnt, name;
	char names[505];
	int lastTimeSeen[alphabetSize];

	scanf("%d", &T);
	REP(tc,T)
	{
	    scanf("%d %d %s", &n, &k, names);
	    FOR(i,alphabetSize) lastTimeSeen[i] = NEVER;
        for(i=0, len=strlen(names), recognizedCnt=0; i<len; i++)
        {
            name = names[i]-'A';
            if( i-lastTimeSeen[name] <= k ) recognizedCnt++;
            lastTimeSeen[name] = i;
        }
        printf("Case %d: %d\n", tc, recognizedCnt);
	}

	fclose(stdout);
    return 0;
}
