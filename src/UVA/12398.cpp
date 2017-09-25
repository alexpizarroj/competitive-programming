#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define set(a,v) memset(a, v, sizeof(a))
#define len(a) (int)(a.length())


const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int a[3][3];

void PlayMove(int r, int c)
{
    int k,i,j;
    a[r][c] = (a[r][c]+1)%10;
    FOR(k,4)
    {
        i=r+dx[k];
        j=c+dy[k];
        if( i >= 0 && i < 3 && j >= 0 && j < 3 )
            a[i][j] = (a[i][j]+1)%10;
    }
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int i,j,len;
    char line[201];
    int caseNo=1;

    while( gets(line) != NULL )
    {
        set(a,0);
        printf("Case #%d:\n", caseNo++);
        len = strlen(line);
        FOR(i,len)
        {
            char &c = line[i];
            j = c-'a';
            PlayMove(j/3, j%3);
        }
        FOR(i,3)
        {
            FOR(j,3)
                if( j == 0 ) printf("%d", a[i][j]);
                else         printf(" %d", a[i][j]);
            puts("");
        }
    }

    return 0;
}
