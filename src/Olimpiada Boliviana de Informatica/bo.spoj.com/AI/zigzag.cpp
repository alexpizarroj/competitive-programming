#include <cstdio>

int main()
{
    int n, m;
	int mat[105][105];
	while ( scanf("%d %d", &n, &m) != EOF )
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);
		int zz = 1;
		for(int i = 0, j = 0, var = -1; j < m; j++, i += var)
		{
			zz &= mat[i][j];
			if ( i == 0 || i == n-1 ) var *= -1;
		}
		puts(zz ? "YES" : "NO");
	}
    return 0;
}
