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

enum NumberType { DEFICIENT, PERFECT, ABUNDANT };

NumberType getType(int n)
{
    int lim = sqrt(n), b, c, sum = 0;
    FORY(c,1,lim)
    {
        if( n%c == 0)
        {
            b = n/c;
            if( c != 1 ) sum += b;
            if( b != c ) sum += c;
        }
    }

    if( sum < n ) return DEFICIENT;
    else if ( sum > n ) return ABUNDANT;
    return PERFECT;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, t;

    printf("PERFECTION OUTPUT\n");
    while ( scanf("%d", &n) != EOF && n != 0 )
    {
        printf("%5d  ", n);
        t = getType(n);
        switch( t )
        {
            case DEFICIENT: { printf("DEFICIENT\n"); break; }
            case PERFECT:   { printf("PERFECT\n"); break; }
            case ABUNDANT:  { printf("ABUNDANT\n"); break; }
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}
