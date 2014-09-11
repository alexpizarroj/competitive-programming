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

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	#endif

	int vec[5], r;

	while ( scanf("%d %d %d %d %d", vec, vec+1, vec+2, vec+3, vec+4), vec[0] != 0 )
	{
	    // Input processing
	    sort(vec, vec+3);
	    if( vec[3] > vec[4] ) swap(vec[3], vec[4]);
	    int &x = vec[1], &y = vec[2], &a = vec[3], &b = vec[4];

	    // Solution
	    if( a < y )
	    {
	        if( a < x )
	        {
	            r = ( y < b ? y+1 : 53); // we win with a card better than y, if and only if, b beats y
	        }
	        else
	        {
	            r = ( x < b ? x+1 : 53); // we win with a card better than x, if and only if, b beats x
	        }
	    }
	    else
	    {
	        r = 1; // we'll always beat him, no matter which card we pick
	    }
	    while ( find(vec, vec+5, r) != vec+5 && r <= 52 )
	    {
	        r++; // try next card if this card is already taken
	    }

	    // Output
	    if( r <= 52 )
            printf("%d\n", r);
        else
            puts("-1");
	}

    return 0;
}
