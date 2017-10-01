#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
using namespace std;

// Clarifications:
// - A line is considered blank only if its len equals zero (white spaces count)
// - When the problem statement says non-letter, it means non-alphanumeric
// - Longest match asks for the the LCS of words (case sensitive)

const int INF = 1e9+7;
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

int dp[1010][1010];
int lcs(const vi &v1, const vi &v2)
{
    int n = v1.size(), m = v2.size();

    fupi(i,0,n) dp[i][0] = 0;
    fupi(j,0,m) dp[0][j] = 0;
    fupi(i,1,n) fupi(j,1,m)
    {
        if ( v1[i-1] == v2[j-1] )
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
    }

    return dp[n][m];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	char s1[1010], s2[1010];
	map<string, int> idmap;
	int n, m, ans, caseNo = 1;
	vi vec1, vec2;

	while ( gets(s1), gets(s2) != NULL )
	{
	    ans = -1, n = strlen(s1), m = strlen(s2);
	    if ( n > 0 && m > 0 )
	    {
	        fup(i,0,n) if ( !(isalpha(s1[i]) || isdigit(s1[i])) ) s1[i]=' ';
            fup(i,0,m) if ( !(isalpha(s2[i]) || isdigit(s2[i])) ) s2[i]=' ';
	        idmap.clear(), vec1.clear(), vec2.clear();
	        ftok(p, s1, " ")
	        {
	            if ( idmap.count(p) == 0 ) idmap[p] = idmap.size();
	            vec1.PB(idmap[p]);
	        }
	        ftok(p, s2, " ")
	        {
	            if ( idmap.count(p) == 0 ) idmap[p] = idmap.size();
	            vec2.PB(idmap[p]);
	        }
	        ans = lcs(vec1, vec2);
	    }

	    printf("%2d. ", caseNo++);
	    if ( ans == -1 ) puts("Blank!");
	    else             printf("Length of longest match: %d\n", ans);
	}

    return 0;
}
