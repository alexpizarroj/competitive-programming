#include <ctime>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <numeric>

#define pb              push_back
#define all(a)          (a).begin(), (a).end()
#define forn(i, n)      for(int i = 0; i < int(n); ++i)
#define fore(i, a, b)   for(int i = int(a); i <= int(b); ++i)
#define foreach(it, a)  for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)

using namespace std;

const int inf = int(1e9+7);
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef long long       i64;
typedef vector<i64>     vi64;

int mat[1005][1005], mat2[1005][1005], res[1005][1005], a[2][2];
bool rotated;

bool isvalid(const int c[1005][1005], int m, int n, bool rvalue)
{
    rotated = rvalue;
    int cur = 0, pos[2];
    forn(row,m)
    {
        pos[0] = 0, pos[1] = 1;
        forn(col,n)
        {
            if ( c[row][col] > 0 )
            {
                if ( c[row][col] != a[cur][0] && c[row][col] != a[cur][1] )
                {
                    return false;
                }
                if ( c[row][col] == a[cur][0] )
                {
                    int v = col&1;
                    pos[v] = 0, pos[1-v] = 1;
                }
                else
                {
                    int v = col&1;
                    pos[v] = 1, pos[1-v] = 0;
                }
                break;
            }
        }
        forn(col,n)
        {
            res[row][col] = a[cur][pos[col&1]];
            if ( c[row][col] != 0 && c[row][col] != res[row][col] )
            {
                return false;
            }
        }
        cur = 1 - cur;
    }
    return true;
}

int main()
{
    int m, n;
    char row[1005];
    while ( cin >> m >> n )
    {
        forn(i,m) 
        {
            scanf("%s", row);
            assert((int)strlen(row) == n);
            forn(j,n) mat[i][j] = mat2[j][i] = row[j]-'0';
        }
        fore(p,1,4) fore(q,p+1,4)
        {
            for(int k = 0, r = 1; r <= 4; r++)
            {
                if ( r != p && r != q ) a[1][k++] = r;
            }
            a[0][0] = p, a[0][1] = q;
            if ( isvalid(mat,m,n,false) || isvalid(mat2,n,m,true) )
            {
                if ( !rotated )
                {
                    forn(i,m)
                    {
                        forn(j,n) printf("%c", res[i][j]+'0');
                        puts("");   
                    }
                }
                else
                {
                    forn(j,m)
                    {
                        forn(i,n) printf("%c", res[i][j]+'0');
                        puts("");
                    }
                }
                goto NextCase;
            }
        }
        puts("0");
NextCase:;
    }
    return 0;
}
