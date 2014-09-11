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

double a, b, c;
inline void solve_eq(double& ans1, double& ans2)
{
    double d = sqrt(b*b-4*a*c);
    ans1 = (-b + d)/(2*a);
    ans2 = (-b - d)/(2*a);
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int T, tc;
	ll r, t, nRings, usedInk;
	double root1, root2;

	cin >> T;
	REP(tc,T)
	{
	    cin >> r >> t;
	    nRings = 0;

        a = 2, b = 2*r-1, c = -t;
	    solve_eq(root1, root2);

	    nRings = ll(root1)-1;
	    do {
	        nRings++;
	        usedInk = nRings*( 2*(nRings+r) - 1 );
	    } while( usedInk <= t );
	    nRings--;

	    cout << "Case #" << tc << ": " << nRings << endl;
	}

	fclose(stdout);
    return 0;
}
