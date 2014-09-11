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


#define MAX_E 10000000
#define MAX_N 10000
int v[MAX_N], mult[MAX_N];

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int T, tc, i;
	int E, R, N;
	ull sum;

	cin >> T;
	REP(tc,T)
	{
        cin >> E >> R >> N;
        FOR(i,N)
        {
            scanf("%d", v+i);
            mult[i] = R;
        }
        mult[N-1] = E;

        for(i=N-2; i>=0; i--)
        {
            if( v[i] >= v[i+1] )
            {
                int take = min( mult[i+1], E-mult[i] );
                mult[i] += take;
                mult[i+1] -= take;
            }
        }

        sum = 0;
        FOR(i,N) sum += static_cast<ll>(v[i]) * mult[i];
        cout << "Case #" << tc << ": " << sum << endl;
	}

	fclose(stdout);
    return 0;
}
