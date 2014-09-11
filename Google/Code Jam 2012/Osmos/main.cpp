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
#include <fstream>
using namespace std;
// }
// defines {
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define tokenize(pc, searchString, tokenString) \
for(char* pc = strtok(searchString, tokenString); pc != NULL; pc = strtok(NULL,tokenString))
#define PB push_back
#define MP make_pair
#define all(a) (a).begin(), (a).end()
#define between(lbound,i,ubound) ((lbound) <= (i) && (i) <= (ubound))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// }
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};

int n;
size_t vec[100];

size_t min_movements(size_t a, size_t remaining)
{
    if( remaining == 0 ) return 0;

    size_t next = vec[n-remaining];
    size_t nMoves = 0;

    while( a <= next )
    {
        a += a-1;
        nMoves++;
    }

    nMoves += min_movements(a+next, remaining-1);
    return min(nMoves, remaining);
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	int tc, T;
    int a, i;

	cin >> T;
	REP(tc,T)
	{
	    scanf("%d %d", &a, &n);
	    FOR(i,n) scanf("%u", vec+i);
	    sort(vec, vec+n);
	    printf("Case #%d: ", tc);
	    if( a==1 )
            printf("%d\n", n);
        else
            printf("%u\n", min_movements(a,n));
	}

	fclose(stdout);
    return 0;
}
