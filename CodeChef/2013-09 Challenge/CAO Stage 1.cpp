#include <cstring>
#include <cstdio>
#include <algorithm>
#define fup(i,a,b)      for(int i = (a); (i) < int(b); i++)
using namespace std;

#define MAX 55
char maze[MAX][MAX];
int r, c;
int le(int x, int y) { int cnt = 0; while ( y >= 0 && maze[x][y] == '^' ) y--, cnt++; return cnt-1; }
int ri(int x, int y) { int cnt = 0; while ( y < c && maze[x][y] == '^' )  y++, cnt++; return cnt-1; }
int to(int x, int y) { int cnt = 0; while ( x >= 0 && maze[x][y] == '^' ) x--, cnt++; return cnt-1; }
int bo(int x, int y) { int cnt = 0; while ( x < r && maze[x][y] == '^' )  x++, cnt++; return cnt-1; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t, cnt;
    scanf("%d", &t);
    while ( t-- )
    {
        cnt = 0;
        scanf("%d %d", &r, &c); getchar();
        fup(i,0,r) gets(maze[i]);
        fup(i,0,r) fup(j,0,c)
        {
            if ( maze[i][j] != '^' ) continue;
            if ( 2 <= min( min( min( le(i,j), ri(i,j) ), to(i,j) ), bo(i,j) ) ) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
