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
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;
const int INF = int(1e9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

char ans[55][55];

// ========================
// UNUSED SECTION BEGINNING
// ========================

int solveNormal(int r, int c, int m)
{
    int row = 0;
    
    fup(i,0,r) fill(ans[i], ans[i]+c, '.'), ans[i][c] = 0;
    ans[r-1][c-1] = 'c';
    while ( m > 0 )
    {
        if ( r-row > 2 )
        {
            if ( m >= c )
            {
                fill(ans[row], ans[row]+c, '*');
                m -= c, ++row;
            }
            else
            {
                if ( c == 2 ) // && r-row > 2
                {
                    if ( row == r-1 )
                    {
                        if ( m == 0 ) m = 1;
                        else ans[row][1] = '*', --m;
                    }
                }
                else
                {
                    // Vertical filling
                    if ( m >= r-row )
                    {
                        fup(i,0,r-row) 
                        {
                            ans[row+i][0] = '*';
                            --m;
                        }
                    }
                    else
                    {
                        fup(i,0,r-row-2) if ( m > 0 )
                        {
                            ans[row+i][0] = '*';
                            --m;
                        }
                    }
                    // Row filling
                    if ( m > 0 )
                    {
                        fup(i,1,c-2) if ( m > 0 )
                        {
                            ans[row][i] = '*';
                            --m;
                        }
                    }
                }
                break;
            }
        }
        else if ( r-row == 2 )
        {
            int col = 0;
            while ( m > 1 ) ans[row][col]=ans[row+1][col]='*', m-=2, ++col;
            if ( col == c-1 )
            {
                if ( m == 0 ) m = 1;
                else ans[row][col] = '*', --m;
            }
            break;
        }
        else // if ( r-row == 1 )
        {
            fup(i,0,m) ans[row][i]='*'; m = 0;
            break;
        }
    }
    
    return m;
}

int solveRotated(int r, int c, int m)
{
    int ret = solveNormal(c,r,m);
    char tmp[55][55];
    
    memcpy(tmp, ans, sizeof ans);
    fup(i,0,r)
    {
        fup(j,0,c) ans[i][j] = tmp[j][i];
        ans[i][c] = 0;
    }
    
    return ret;
}

bool isSolution(int r, int c, int m, char solans[55][55])
{
    int dr[] = {0,0,1,-1, 1,1,-1,-1}, dc[] = {1,-1,0,0, 1,-1,1,-1};
    char sol[55][55];
    
    memcpy(sol, solans, sizeof sol);
    fup(i,0,r) fup(j,0,c) if ( sol[i][j] != '*' ) sol[i][j] = '0';
    fup(i,0,r) fup(j,0,c) if ( sol[i][j] == '*' ) fup(k,0,8)
    {
        int ip = i+dr[k], jp = j+dc[k];
        if ( 0 <= ip && ip < r && 0 <= jp && jp < c && sol[ip][jp] != '*' )
        {
            ++sol[ip][jp];
        }
    }
    //puts(""); fup(i,0,r) printf("%s\n", sol[i]);
    
    bool visited[55][55] = {0};
    queue<ii> q;
    int cnt = 1, sr, sc;
    
    for(sr=0; sr<r; sr++) for(sc=0; sc<c; sc++)
    {
        if ( sol[sr][sc] == '0' ) 
        {
            solans[sr][sc] = 'c';
            goto outOfLoop;
        }
    }
outOfLoop:
    if ( sr == r ) goto endOfSub;
    q.push(ii(sr, sc));
    visited[sr][sc] = true;
    
    while ( !q.empty() )
    {
        ii next = q.front(); q.pop();
        int row = next.first, col = next.second;
        if ( sol[row][col] == '0' )
        {
            fup(k,0,8)
            {
                int ip = row+dr[k], jp = col+dc[k];
                if ( 0 <= ip && ip < r && 0 <= jp && jp < c && !visited[ip][jp] )
                {
                    visited[ip][jp] = true;
                    q.push(ii(ip,jp));
                    ++cnt;
                }
            }
        }
    }
    
endOfSub:
    return (cnt == r*c-m);
}

bool bruteforce(int r, int c, int m)
{
    int vec[25]={0}, n=r*c;
    char candidate[55][55];
    
    fup(i,0,m) vec[n-i-1]=1;
    do
    {
        fup(i,0,r)
        {
            fup(j,0,c) candidate[i][j] = (vec[i*r+j] == 1 ? '*' : '.');
            candidate[i][c] = 0;
        }
        if ( isSolution(r,c,m,candidate) )
        {
            //puts("Bruteforce Solution Found");
            fup(i,0,r) strcpy(ans[i], candidate[i]);
            return true;
        }
    } while ( next_permutation(vec, vec+n) );
    
    //puts("Bruteforce Solution Not Found");
    return false;
}

void backtrackSlow(int r, int c, int m)
{
    int ret = solveNormal(r,c,m);
    if ( ret > 0 ) ret = solveRotated(r,c,m);
    if ( ret > 0 ) bruteforce(r,c,m);
}

// =====================
// UNUSED SECTION ENDING
// =====================

bool f[51][51][2500];

void backtrack(int r, int c, int m)
{
    int osr = 0, osc = 0;
    
    fup(i,0,r) fill(ans[i], ans[i]+c, '.'), ans[i][c] = 0;
    ans[r-1][c-1] = 'c';
    while ( m > 0 )
    {
        if ( r == 1 )
        {
            fup(i,0,m) ans[osr+0][osc+i] = '*';
            m = 0;
        }
        else if ( c == 1 )
        {
            fup(i,0,m) ans[osr+i][osc+0] = '*';
            m = 0;
        }
        else if ( r == 2 )
        {
            int d = 0;
            while ( m > 1 ) 
            {
                ans[osr][osc+d] = ans[osr+1][osc+d] = '*';
                ++d, m -= 2;
            }
            if ( m == 1 ) ans[osr][osc+d] = '*', --m;
            assert(m == 0);
        }
        else if ( c == 2 )
        {
            int d = 0;
            while ( m > 1 ) 
            {
                ans[osr+d][osc] = ans[osr+d][osc+1] = '*';
                ++d, m -= 2;
            }
            if ( m == 1 ) ans[osr+d][osc] = '*', --m;
            assert(m == 0);
        }
        else // if ( r, c >= 3 )
        {
            if ( m <= r+c-5 )
            {
                fup(i,0,r-2) if ( m > 0 )
                {
                    ans[osr+i][osc] = '*';
                    --m;
                }
                fup(i,1,c-2) if ( m > 0 )
                {
                    ans[osr][osc+i] = '*';
                    --m;
                }
                assert(m == 0);
            }
            else if ( m >= r && f[r][c-1][m-r] )
            {
                fup(i,0,r) ans[osr+i][osc] = '*';
                --c, ++osc, m -= r;
            }
            else // if ( m >= c && f[r-1][c][m-c] )
            {
                fup(i,0,c) ans[osr][osc+i] = '*';
                --r, ++osr, m -= c;
            }
        }
    }
}

int main()
{
    int tc, r, c, m;
    
    // DP
    fupi(i,2,50) fup(k,0,2*i)
    {
        f[2][i][k] = f[i][2][k] = ( (k&1)==0 ? (k/2)!=i-1 : (k/2)==i-1 );
    }
    fupi(i,1,50) fup(k,0,i) f[1][i][k] = f[i][1][k] = true;
    fupi(i,1,50) fupi(j,1,50) f[i][j][0] = f[i][j][i*j-1] = true;
    fupi(i,3,50) fupi(j,3,50) fup(k,0,i*j)
    {
        f[i][j][k] = (k <= i+j-5);
        if ( !f[i][j][k] && k >= i ) f[i][j][k] = f[i][j-1][k-i];
        if ( !f[i][j][k] && k >= j ) f[i][j][k] = f[i-1][j][k-j];
    }
    
    scanf("%d", &tc);
    fupi(caseno, 1, tc)
    {
        printf("Case #%d:\n", caseno);
        scanf("%d %d %d", &r, &c, &m);
        if ( f[r][c][m] )
        {
            backtrack(r, c, m);
            fup(i,0,r) printf("%s\n", ans[i]);
        }
        else puts("Impossible");
    }
	
    return 0;
}
