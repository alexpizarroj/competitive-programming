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

char m[100][100];


pair<int,int> match(string a, string b)
{
    int i, j;
    int lenA = a.length(), lenB = b.length();

    FORX(i,0,lenA)
        FORX(j,0,lenB)
            if( a[i] == b[j] ) return make_pair(i,j);

    return make_pair(-1,-1);
}

void writeH(string a, int row, int col)
{
    int i, j, len = a.length();
    if( len == 0 ) return;

    // Escribir palabra
    FORX(i,0,len)
    {
        m[row][col] = a[i];
        col++;
    }
    // Espaciar
    col -= 1;
    i = row;
    FORY(j,0,col)
        if( m[i][j] == 0 )
            m[i][j] = ' ';
}

void writeV(string a, int row, int col)
{
    int i, j, row0 = row, len = a.length();
    if( len == 0 ) return;

    // Escribir palabra
    FORX(i,0,len)
    {
        m[row][col] = a[i];
        row++;
    }
    // Espaciar
    row -= 1;
    FORY(i,row0,row)
    {
        FORY(j,0,col)
        {
            if( m[i][j] == 0 )
                m[i][j] = ' ';
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string a, b, c, d;
    int ntest = 0, i, j, firstStart;
    pair<int,int> p1, p2;
    bool solved;

    while ( true )
    {
        // Entrada
        cin >> a;
        if( a == "#" ) break;
        cin >> b >> c >> d;
        firstStart = 0;
        p1 = match(a,b);
        p2 = match(c,d);
        solved = (p1.first != -1) && (p2.first != -1);
        p2.first = a.length()+ 3+ p2.first;
        p2.second = p1.second-p2.second;
        if( p2.second < 0 )
        {
            firstStart = abs(p2.second);
            p1.second += firstStart;
            p2.second = 0;
        }

        // Resolucion
        if( solved )
        {
            memset(m, 0, sizeof m);
            // Cruz uno
            writeH(a, p1.second, 0);
            writeV(b, firstStart, p1.first);
            // Cruz dos
            writeH(c, p1.second, a.length()+3);
            writeV(d, p2.second, p2.first);
        }

        // Salida
        if( ntest++ > 0 ) printf("\n");
        if( solved )
        {
            for(i = 0; m[i][0] != 0; i++)
            {
                for(j = 0; m[i][j] != 0; j++)
                    printf("%c", m[i][j]);
                if(j > 0) printf("\n");
            }
        }
        else
            printf("Unable to make two crosses\n");
    }

    fclose(stdout);
    return 0;
}
