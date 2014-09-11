#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
char ma[15][15];
int dist[15][15];
const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
typedef pair<int,int> ii;

int minCost(int x1, int y1, int x2, int y2)
{
	queue<ii> q;
	memset(dist, -1, sizeof dist);
	dist[x1][y1] = 0;
	q.push(ii(x1,y1));
	while ( !q.empty() )
	{
		ii cur = q.front();
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int xx = cur.first + dx[k], yy = cur.second + dy[k];
			if ( 0 <= xx && xx < 10 && 0 <= yy && yy < 10 )
			{
				if ( ma[xx][yy] != 'x' && dist[xx][yy] == -1 )
				{
					dist[xx][yy] = dist[cur.first][cur.second] + 1;
					q.push(ii(xx,yy));
				}
			}
		}
	}
	return dist[x2][y2];
}

int main()
{
	while ( scanf("%s", ma[0]) != EOF )
	{
		for(int i = 1; i < 10; i++)
			scanf("%s", ma[i]);
		char pochar[] = {'m', 'k', 'e'};
		int po[3][2];
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				for(int k = 0; k < 3; k++)
					if ( ma[i][j] == pochar[k] )
						po[k][0] = i, po[k][1] = j;
		int start_key = minCost(po[0][0], po[0][1], po[1][0], po[1][1]);
		int key_end = minCost(po[1][0], po[1][1], po[2][0], po[2][1]);
		printf("%d\n", start_key + key_end);
	}
}