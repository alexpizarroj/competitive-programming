#include <cassert>
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
#include <cmath>
#include <climits>
#include <cctype>
#include <fstream>
#include <bitset>
#define PB 				        push_back
#define MP 				        make_pair
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fdo(i,a,b) 		        for(int i = (a); (i) > int(b); i--)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define fdoi(i,a,b) 		    for(int i = (a); (i) >= int(b); i--)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define dall(a)		 	        (a).begin(), (a).end()
#define dset(a,v) 		        memset(a, v, sizeof(a))
#define dclr(a)         	 	memset(a, 0, sizeof(a))
#define least_first_heap(T)     priority_queue<T, deque<T>, greater<T> >
using namespace std;

typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pii; typedef vector<int> vi;
template<class T> bool inline between(const T& lb, const T& v, const T& ub) { return lb<=v && v<=ub; }
const int INF = int(1E9+7);

bool mat[5][5];
int mp[100];

inline bool bingoFrom(int f, int c)
{
    bool bingo = true;
    mat[f][c] = true;

    if( f == 2 && c == 0 )
    {
        f = 2;
    }

    // horizontal
    fup(i,0,5) if( !mat[f][i] ) { bingo = false; break; }
    // vertical
    if( !bingo )
    {
        bingo = true;
        fup(i,0,5) if( !mat[i][c] ) { bingo = false; break; }
    }
    // main diagonal
    if( !bingo )
    {
        bingo = true;
        fup(i,0,5) if( !mat[i][i] ) { bingo = false; break; }
    }
    // secondary diagonal
    if( !bingo )
    {
        bingo = true;
        fup(i,0,5) if( !mat[i][4-i] ) { bingo = false; break; }
    }

    return bingo;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	#endif

	int n, r, k;
	bool bingo;

	scanf("%d", &n);
	while ( n-- )
	{
	    // Input
	    dset(mp, -1);
	    fup(i,0,5)
	    {
	        fup(j,0,5)
	        {
	            if ( i==2 && j==2 ) continue;
                scanf("%d", &k);
                mp[k] = i*5 + j;
	        }
	    }

	    // Input + Processing
	    dclr(mat); mat[2][2] = true;
	    r = 0, bingo = false;
	    fup(i,0,75)
	    {
	        scanf("%d", &k);
            if ( !bingo ) r++;
            if ( !bingo && mp[k] != -1 )
                bingo = bingoFrom(mp[k]/5, mp[k]%5);
        }

	    // Output
	    printf("BINGO after %d numbers announced\n", r);
	}

    return 0;
}
