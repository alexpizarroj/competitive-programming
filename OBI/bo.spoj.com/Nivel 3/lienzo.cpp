#include <cstdio>

int dx[] = {0,0,-1,1,1,1,-1,-1}, dy[] = {-1,1,0,0,1,-1,1,-1};
int n, m, c, target, mat[100][100];

void dfs(short i, short j)
{
    mat[i][j] = 0;
    for(int cnt = 0; cnt < 8; cnt++)
    {
        short x = i + dx[cnt], y = j + dy[cnt];
        if( 0 <= x && x < n && 0 <= y && y < m && mat[x][y] == target )
            dfs(x, y);
    }
}

int main()
{
	int ans;
	while ( scanf("%d %d %d", &n, &m, &c), n || m || c )
    {
        ans = 0;
        if( n > 0 && m > 0 )
        {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    scanf("%d", &mat[i][j]);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if ( mat[i][j] != c && mat[i][j] != 0 )
                        ans++, target = mat[i][j], dfs(i,j);
        }
        printf("%d\n", ans);
    }
    return 0;
}

