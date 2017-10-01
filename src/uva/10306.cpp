#include <cstdio>
#include <cstring>
#include <algorithm>
#define NO_PROBADO -1
#define IMPOSIBLE  -2

using namespace std;

typedef pair<int,int> pii;
int tabla[301][301];
pii moneda[40];
int s, m;

int MenorCantidadMonedas(int x, int y)
{
    if( x < 0 || y < 0 )            return IMPOSIBLE;
    if( tabla[x][y] != NO_PROBADO ) return tabla[x][y];

    int mejor = IMPOSIBLE, actual, i;
    for(i=0; i<m; i++)
    {
        actual = MenorCantidadMonedas(x-moneda[i].first, y-moneda[i].second);
        if( actual != IMPOSIBLE )
        {
            if( mejor == IMPOSIBLE )    mejor = actual + 1;
            else                        mejor = min( mejor, actual+1  );
        }
    }

    return (tabla[x][y] = mejor);
}


int main()
{
    //freopen("data.in", "r", stdin);
    int t, i, j, mejor, actual, fisico, digital;

    scanf("%d", &t);
    while ( t-- )
    {
        memset(tabla, NO_PROBADO, sizeof tabla);
        tabla[0][0] = 0;

        scanf("%d %d", &m, &s);
        for(i=0;i<m;i++)
        {
            scanf("%d %d", &fisico, &digital);
            tabla[fisico][digital] = 1;
            moneda[i].first  = fisico;
            moneda[i].second = digital;
        }

        mejor = NO_PROBADO;
        for(i=0; i<=s; i++)
            for(j=0; j<=s; j++)
                if( i*i + j*j == s*s )
                {
                    actual = MenorCantidadMonedas(i, j);
                    if( actual != IMPOSIBLE )
                    {
                        if( mejor == NO_PROBADO )     mejor = actual;
                        else                          mejor = min(actual, mejor);
                    }
                }

        if( mejor == -1 )
            puts("not possible");
        else
            printf("%d\n", mejor);
    }

    return 0;
}
