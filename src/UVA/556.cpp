#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#define PB push_back
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
using namespace std;

typedef vector<int> vi;
vector<string> maze;
int freq[5];

void process()
{
    vector<vi> mfreq(maze.size(), vi(maze[0].size(), 0));
    int baser = maze.size()-2, basec = 1;
    int r, c, dr, dc, tr, tc;
    bool valid_wall;

    memset(freq, 0, sizeof freq);
    r = baser, c = basec, dr = 0, dc = 1;
    while ( mfreq[baser][basec] < 2 )
    {
        tr = r+dr, tc = c+dc;
        if ( maze[tr][tc] == '0' ) // Can move
        {
            ++mfreq[r][c], ++mfreq[tr][tc];
            valid_wall = (maze[tr+dc][tc-dr] == '1');
            swap(r, tr), swap(c, tc); // Move forward
            if ( !valid_wall )
            {
                swap(dr, dc); dc *= -1;
                ++mfreq[r][c], ++mfreq[r+dr][c+dc];
                r = r+dr, c = c+dc; // Move right to preserve right wall
            }
        }
        else // Cannot move, turn left
        {
            swap(dr, dc); dr *= -1;
        }
    }

    fup(i,0,maze.size()) fup(j,0,maze[0].size())
    {
        if ( maze[i][j] == '1' ) continue;
        ++freq[ mfreq[i][j]/2 ];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int h, w, bufsz = 0;
	char *buffer = NULL;

	while ( scanf("%d %d", &h, &w), h || w )
	{
        getchar();
        // Buffer update
        if ( bufsz < w )
        {
            if ( buffer ) delete[] buffer;
            buffer = new char[w+3];
            bufsz = w;
        }
        // Maze reading
        maze.clear();
        maze.PB( string(w+2, '1') );
        buffer[0] = buffer[w+1] = '1';
        buffer[w+2] = 0;
        fup(i,0,h)
        {
            gets(buffer+1);
            buffer[w+1] = '1';
            maze.PB(buffer);
        }
        maze.PB(maze.front());
        // Maze traversal
        process();
        // Output
        fupi(i,0,4) printf("%3d", freq[i]);
        puts("");
	}

	if ( buffer ) delete[] buffer;

    return 0;
}
