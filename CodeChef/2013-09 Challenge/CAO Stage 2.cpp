#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define fup(i,a,b)      for(int i = (a); (i) < int(b); i++)
using namespace std;

#define MAX 505
char maze[MAX][MAX];
int r, c;

struct data_t { int le, ri, to, bo; } memo[MAX][MAX];
inline int to(int x, int y)
{
	int &ans = memo[x][y].to;
	if ( ans == -1 ) ans = ( x > 0 && maze[x-1][y] == '^' ? to(x-1,y) + 1 : 0 );
	return ans;
}
inline int bo(int x, int y)
{
	int &ans = memo[x][y].bo;
	if ( ans == -1 ) ans = ( x+1 < r && maze[x+1][y] == '^' ? bo(x+1,y) + 1 : 0 );
	return ans;
}
inline int le(int x, int y)
{
	int &ans = memo[x][y].le;
	if ( ans == -1 ) ans = ( y > 0 && maze[x][y-1] == '^' ? le(x,y-1) + 1 : 0 );
	return ans;
}
inline int ri(int x, int y)
{
	int &ans = memo[x][y].ri;
	if ( ans == -1 ) ans = ( y+1 < c && maze[x][y+1] == '^' ? ri(x,y+1) + 1 : 0 );
	return ans;
}

bool prime[MAX];
vector<int> primes;
void run_sieve()
{
    primes.clear();
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for(int i = 2; i*i < MAX; i++)
    {
		if ( !prime[i] ) continue; 
        for(int j = i*i; j < MAX; j+=i)
        {
            prime[j] = false;
        }
    }
    for(int i = 0; i < MAX; i++)
    {
        if( prime[i] ) primes.push_back(i);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t, cnt;
	run_sieve();
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d %d", &r, &c); getchar();
        fup(i,0,r) gets(maze[i]);

        cnt = 0;
		memset(memo, -1, sizeof memo);
        fup(i,0,r) fup(j,0,c)
        {
            if ( maze[i][j] != '^' ) continue;
            int searchedValue = min( min( min( le(i,j), ri(i,j) ), to(i,j) ), bo(i,j) );
            cnt += distance(primes.begin(), upper_bound(primes.begin(), primes.end(), searchedValue));
        }

        printf("%d\n", cnt);
    }
    return 0;
}
