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

int reg[4][4];

bool theyMakeSquare(i64 x[], i64 y[], bool verbose = false)
{
	int vec[] = {0, 1, 2, 3};
	do
	{
		i64 xx[4], yy[4];
		xx[0] = x[vec[0]];
		yy[0] = y[vec[0]];
		pair<i64, i64> move_vector(x[vec[1]] - xx[0], y[vec[1]] - yy[0]);
		if ( move_vector.first != 0 || move_vector.second != 0 )
		{
			fore(i,1,3)
			{
				xx[i] = xx[i-1] + move_vector.first;
				yy[i] = yy[i-1] + move_vector.second;
				swap(move_vector.first, move_vector.second);
				move_vector.second *= -1;
			}
			bool good = true;
			forn(i,4)
				if ( xx[i] != x[vec[i]] || yy[i] != y[vec[i]] )
					{ good = false; break; }
			if ( good )
				return true;
		}
	}
	while ( next_permutation(vec, vec+4) );
	return false;
}

int solve()
{
    int ans = inf;
    i64 x[4], y[4], hx[4], hy[4];
    forn(i,4) forn(j,4) forn(k,4) forn(m, 4)
    {
        int rot[4] = {i, j, k, m};
        for(int n = 0; n < 4; n++)
        {
            x[n] = reg[n][0],  y[n] = reg[n][1];
            hx[n] = reg[n][2], hy[n] = reg[n][3];
            forn(o, rot[n])
            {
                i64 xx = x[n], yy = y[n];
                x[n] = hx[n] + hy[n] - yy;
                y[n] = hy[n] - hx[n] + xx;
            }
        }
        int cost = i + j + k + m;
        // if ( cost == 8 )
        // {
        // 	forn(iter, 4) cout << "Punto: " << x[iter] << ", " << y[iter] << endl;
        // 	cout << "Resultados: " << theyMakeSquare(x, y, true) << endl << endl;
        // }
        if ( cost < ans && theyMakeSquare(x, y) )
            ans = cost;
    }
    return (ans == inf ? -1 : ans);
}

int main()
{
	int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                scanf("%d", &reg[j][k]);
        printf("%d\n", solve());
    }
    return 0;
}