/*
ID: alex.pi1
PROG: beads
LANG: C++
*/
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
#define PB 				        push_back
#define MP 				        make_pair
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fdo(i,a,b) 		        for(int i = (a); (i) > int(b); i--)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define fdoi(i,a,b) 		    for(int i = (a); (i) >= int(b); i--)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define all(a)		 	        (a).begin(), (a).end()
#define set(a,v) 		        memset(a, v, sizeof(a))
#define clr(a)         	 	    memset(a, 0, sizeof(a))
#define least_first_heap(T)     priority_queue<T, deque<T>, greater<T> >
using namespace std;

typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii;
template<class T> bool inline between(const T& lb, const T& v, const T& ub) { return lb<=v && v<=ub; }
const int INF = int(1E9+7);

inline int movpos(int pos, int mov, int len)
{
    if( mov > 0 )
        pos = (pos+mov)%len;
    else
    {
        pos += mov;
        while( pos < 0 ) pos += len;
    }
    return pos;
}

int get(int pos, int mov, char *str, int len, int maxBeads)
{
    int r = 0; char target;

    while( str[pos] == 'w' && r < maxBeads )
        pos = movpos(pos,mov,len), r++;

    if( str[pos] == 'r' )   target = 'b';
    else                    target = 'r';

    while( str[pos] != target && r < maxBeads )
        pos = movpos(pos,mov,len), r++;

    return r;
}

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

	int n, len, best, current;
	char str[400];

	while( scanf("%d", &n) != EOF )
	{
	    getchar();
        gets(str);

        best = 0;
        len = strlen(str);
        fup(i,0,len)
        {
            if( str[i] == 'w' ) continue;
            current = get(i, -1, str, len, len);
            current += get((i+1)%len, 1, str, len, len-current);
            best = max(best, current);
        }
        if( best == 0 ) best = len;

        printf("%d\n", best);
	}

    fclose(stdout);
    return 0;
}
