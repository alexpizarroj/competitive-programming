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
#define MSB(n) ( n <= 0 ? 0 : int(floor(log(n)/log(2))) )
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;

const int INF = int(1E9+7);
const double EPS = 1e-6;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int dx[] = {2, -2,  2,  -2};
const int dy[] = {2,  2, -2,  -2};
int r[2][8][8];
vector<string> board;

void dfs(int i, int j, int moves, const int m)
{
    if ( i < 0 || i >= 8 || j < 0 || j >= 8 || r[m][i][j] ) return;

    r[m][i][j] = moves;
    fup(k,0,4) dfs(i + dx[k], j + dy[k], moves+1, m);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	string row;
	int n, cnt;
	bool yes;

	cin >> n;
	while ( n-- )
	{
        board.clear();
        fup(i,0,8)
        {
            cin >> row;
            board.PB(row);
        }

        memset(r, false, sizeof r); cnt = 0;
        fup(i,0,8) fup(j,0,8)
        {
            if ( board[i][j] == 'K' ) { dfs(i, j, 1, cnt++); board[i][j] = '.'; }
        }

        yes = false;
        fup(i,0,8) fup(j,0,8)
        {
            if ( board[i][j] == '.' && r[0][i][j] && r[1][i][j] &&  (r[0][i][j]%2 == r[1][i][j]%2) ) yes = true;
        }
        puts(yes ? "YES" : "NO");
	}

    return 0;
}
