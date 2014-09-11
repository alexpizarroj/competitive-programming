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

#define MAX 105
char g1[MAX][MAX];
char g2[MAX][MAX];
char (*p1)[MAX][MAX], (*p2)[MAX][MAX];
char enemy[256];

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	#endif

	int tc, r, c, n;

    dclr(g1); dclr(g2);
    enemy['R'] = 'P', enemy['P'] = 'S', enemy['S'] = 'R';

	scanf("%d", &tc); getchar();
	fup(TC, 0, tc)
	{
	    scanf("%d %d %d", &r, &c, &n); getchar();
	    fupi(i, 1, r)
	    {
	        gets(g1[i]+1);
	    }

        p1 = &g1, p2 = &g2;
	    while ( n-- )
	    {
	        fupi(i, 1, r)
	        {
	            fupi(j, 1, c)
	            {
	                const char &c1 = (*p1)[i][j];
	                const char &c2 = enemy[int(c1)];
	                if( (*p1)[i-1][j] == c2 || (*p1)[i+1][j] == c2 ||
                        (*p1)[i][j-1] == c2 || (*p1)[i][j+1] == c2)
                    {
                        (*p2)[i][j] = c2;
                    }
                    else
                    {
                        (*p2)[i][j] = c1;
                    }
	            }
	        }
	        swap(p1, p2);
	    }

        if( TC > 0 ) puts("");
	    fupi(i, 1, r)
	    {
            printf("%s", (*p1)[i]+1);
	        puts("");
	    }
	}

    return 0;
}
