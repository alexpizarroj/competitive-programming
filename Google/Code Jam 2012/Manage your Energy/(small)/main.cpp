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

#define MAX_E 100
#define MAX_INDEX 100
#define NOT_TRIED -1
int dp[MAX_E+1][MAX_INDEX];
int max_E, v[10], R;

int max_gain(int energy, int index)
{
    if( energy < 0 || index < 0 ) return 0;

    if( dp[energy][index] == NOT_TRIED )
    {
        int i, gain, best=0;
        int new_energy, new_index = index-1;

        for(i=0; i<=energy; i++)
        {
            new_energy = min(energy-i+R, max_E);

            gain = v[index]*i;
            if( new_index >= 0 ) gain += max_gain( new_energy, new_index);
            best = max(best, gain);
        }
        dp[energy][index] = best;
    }

    return dp[energy][index];
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int T, tc, i;
	int E, N;

	cin >> T;
	REP(tc,T)
	{
        cin >> E >> R >> N;
        for(i=N-1; i>=0; i--) cin >> v[i];

        SET(dp, NOT_TRIED); max_E = E;
        cout << "Case #" << tc << ": " << max_gain(E,N-1) << endl;
	}

	fclose(stdout);
    return 0;
}
