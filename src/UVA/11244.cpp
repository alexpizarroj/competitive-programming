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

#define MAX 102
#define D 8
char m[MAX][MAX];
int r, c;
int dx[8] = {0, 0,1,-1,1, 1,-1,-1};
int dy[8] = {1,-1,0, 0,1,-1, 1,-1};


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int i, j, k, stars;
    bool star;

    while ( scanf("%d %d", &r, &c) && r > 0 && c > 0 )
    {
        // Entrada
        getchar();
        FORX(i,0,MAX)
        {
            FORX(j,0,MAX) m[i][j] = '.';
        }
        FORY(i,1,r)
        {
            scanf("%s", m[i]+1); getchar();
            m[i][c+1] = '.';
        }

        // Comprobar entrada
        /*FORY(i,0,r+1)
        {
            FORY(j,0,c+1) printf("%c", m[i][j]);
            printf("\n");
        }
        printf("------------\n");*/

        // Resolver
        stars = 0;
        FORY(i,1,r) FORY(j,1,c)
        {
            if( m[i][j] == '.' ) continue;
            star = true;
            FORX(k,0,D)
            {
                if( m[ i+dx[k] ][ j+dy[k] ] == '*' )
                {
                    star = false;
                    break;
                }
            }
            if( star ) stars++;
        }

        // Salida
        printf("%d\n", stars);
    }

    return 0;
}
