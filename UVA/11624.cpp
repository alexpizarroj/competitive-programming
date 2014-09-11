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

#define MAX 1000
struct Punto {
    Punto() {}
    Punto(int r1, int c1) {
        r = r1;
        c = c1;
    }
    int r, c;
};
#define MOVES 4
int dx[MOVES] = {0,0,1,-1};
int dy[MOVES] = {1,-1,0,0};
char maze[MAX][MAX+1];
int r, c;


inline bool estaDentro(int x, int y) {
    return ( x >= 0 && x < r ) && ( y >= 0 && y < c );
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int T, mr, mc, i, j, ans;
    int cntJohn, newInJohn, cntFire, newInFire;
    queue<Punto> john;
    queue<Punto> fire;
    Punto p;


    scanf("%d", &T); getchar();
    while ( T-- )
    {
        // Entrada
        scanf("%d %d", &r, &c); getchar();
        FORX(i,0,r) gets(maze[i]);
        while( !john.empty() ) john.pop();
        while( !fire.empty() ) fire.pop();

        // Leer posiciones iniciales
        cntJohn = cntFire = newInJohn = newInFire = 0;
        FORX(i,0,r) FORX(j,0,r)
        {
            if( maze[i][j] == 'F' )
            {
                fire.push(Punto(i,j));
                newInFire++;
            }
            else if( maze[i][j] == 'J' )
            {
                john.push(Punto(i,j));
                newInJohn++;
            }
        }

        // Resolver
        ans = 0;
        while ( true )
        {
            cntJohn = newInJohn;
            cntFire = newInFire;
            newInJohn = newInFire = 0;
            // Comprobar
            if( cntJohn == 0 )
            {
                // Perdemos
                ans = -1;
                goto sub_final;
            }
            // John
            while ( cntJohn-- )
            {
                p = john.front(); john.pop();
                if( maze[p.r][p.c] != 'J' ) continue;
                // Comprobar posibles movidas de John
                FORX(i,0,MOVES)
                {
                    mr = p.r + dx[i];
                    mc = p.c + dy[i];
                    if( estaDentro(mr, mc) )
                    {
                        if( maze[mr][mc] == '.' )
                        {
                            john.push(Punto(mr,mc));
                            maze[mr][mc] = 'J';
                            newInJohn++;
                        }
                    }
                    else
                    {
                        // Ganamos
                        ans++;
                        goto sub_final;
                    }
                }
            }
            // Fuego
            while ( cntFire-- )
            {
                p = fire.front(); fire.pop();
                FORX(i,0,MOVES)
                {
                    mr = p.r + dx[i];
                    mc = p.c + dy[i];
                    if( estaDentro(mr, mc) )
                    {
                        if( maze[mr][mc] == '.' || maze[mr][mc] == 'J' )
                        {
                            fire.push(Punto(mr,mc));
                            maze[mr][mc] = 'F';
                            newInFire++;
                        }
                    }
                }
            }
            // Sumar minuto
            ans++;
        }

        // Salida
        sub_final:
        if( ans == -1 ) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }

    return 0;
}
