#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <list>
#include <sstream>
#include <string>
#include <cstring>

#include <memory.h>
#include <algorithm>
#include <cmath>

#define FORX(i,start,end) for(i=start;i<end;i++)
#define FORY(i,start,end) for(i=start;i<=end;i++)

using namespace std;

#define MAX_N 25
#define MOVES 8
int n;
char maze[MAX_N][MAX_N+1];
int dx[MOVES] = {0,0,1,-1, 1, 1,-1,-1};
int dy[MOVES] = {1,-1,0,0, 1,-1, 1,-1};
inline bool isInside(int r, int c) { return ( r > -1 && r < n ) && ( c > -1 && c < n ); }

void dfs(int r, int c)
{
    int i, j, k;
    maze[r][c] = '0';
    FORX(k,0,MOVES)
    {
        i = r + dx[k];
        j = c + dy[k];
        if( isInside(i,j) && maze[i][j] == '1' )
            dfs(i,j);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int i, j, eagles;
    int caseNo = 1;

    while ( scanf("%d", &n) != EOF )
    {
        // Entrada
        getchar();
        FORX(i,0,n) gets(maze[i]);

        // Resolucion
        eagles = 0;
        FORX(i,0,n) FORX(j,0,n)
            if( maze[i][j] == '1' )
            {
                dfs(i,j);
                eagles++;
            }

        // Salida
        printf("Image number %d contains %d war eagles.\n", caseNo++, eagles);
    }

    return 0;
}
