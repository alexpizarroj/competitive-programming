#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int inf = int(1e9+7);
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef pair<int,ii>	iii;

int mat[1000][1000], n, m;
const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

int solve(const int x1, const int y1, const int x2, const int y2)
{
	vector<vi> dist(n, vi(m, inf));
	priority_queue< iii, vector<iii>, greater<iii> > q;
	
	dist[x1][y1] = mat[x1][y1];
	q.push( make_pair(dist[x1][y1], ii(x1,y1)) );
	while ( !q.empty() )
	{
		int x = q.top().second.first, y = q.top().second.second;
		int d = q.top().first;
		q.pop();
		if ( dist[x][y] != d ) continue;
		if ( x == x2 && y == y2 ) break;
		for(int k = 0; k < 4; k++)
		{
			int xx = x + dx[k], yy = y + dy[k];
			if ( 0 <= xx && xx < n && 0 <= yy && yy < m )
			{
				if ( dist[x][y] + mat[xx][yy] < dist[xx][yy] )
				{
					dist[xx][yy] = dist[x][y] + mat[xx][yy];
					q.push( make_pair(dist[xx][yy], ii(xx,yy)) );
				}
			}
		}
	}
	return dist[x2][y2];
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while ( tc-- )
	{
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);
		printf("%d\n", solve(0,0,n-1,m-1));
	}
    return 0;
}
