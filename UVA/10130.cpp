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

#define MAX_N 1000
struct Object {
    int price, weight;
} obj[MAX_N];
bool cmp(Object a, Object b) { return a.weight < b.weight; }
#define MAX_G 100
int group[MAX_G];
#define MAX_W 30
#define NOT_TRIED -1
int memo[MAX_W+1][MAX_N+1];
int n, g;


int solve(int mw, int fromStart)
{
    if( fromStart >= n || mw < 1 ) return 0;
    if( memo[mw][fromStart] != NOT_TRIED ) return memo[mw][fromStart];

    int i = fromStart, best = 0;
    while( i < n && obj[i].weight <= mw )
    {
        best = max(best, obj[i].price + solve(mw - obj[i].weight, i+1));
        i++;
    }

    return memo[mw][fromStart] = best;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int T, sum, i;

    scanf("%d", &T);
    while( T-- )
    {
        // Entrada
        scanf("%d", &n);
        FORX(i,0,n)
        {
            scanf("%d %d", &obj[i].price, &obj[i].weight);
        }
        sort(obj, obj+n, cmp);
        //FORX(i,0,n) printf("* %d\n", obj[i].weight);
        scanf("%d", &g);
        FORX(i,0,g)
        {
            scanf("%d", &group[i]);
        }
        sort(group, group+g);

        // Resolucion
        sum = 0;
        memset(memo, NOT_TRIED, sizeof memo);
        FORX(i,0,g) sum += solve(group[i], 0);

        // Salida
        printf("%d\n", sum);
    }

    return 0;
}
