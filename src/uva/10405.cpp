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
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define LEN(a) (int)(a).length()
#define SQR(a) (a)*(a)
#define PB push_back
#define MP make_pair
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// }
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define MAX 1000
int table[MAX+1][MAX+1];
int lcs_len(const char *sz1, const char *sz2)
{
    int n=strlen(sz1), m=strlen(sz2);

    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
        {
            if( i==0 || j == 0 )
                table[i][j] = 0;
            else if( sz1[i-1] == sz2[j-1] )
                table[i][j] = table[i-1][j-1]+1;
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }

    return table[n][m];
}

char line1[MAX+1], line2[MAX+1];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    while( gets(line1) && gets(line2) )
        printf("%d\n", lcs_len(line1, line2));

    return 0;
}
