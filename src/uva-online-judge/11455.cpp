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
#define fup(i,a,b) 		        for(int i = (a); (i) < (b); i++)
#define fdo(i,a,b) 		        for(int i = (a); (i) > (b); i--)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= (b); i++)
#define fdoi(i,a,b) 		    for(int i = (a); (i) >= (b); i--)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define container(a) 	        (a).begin(), (a).end()
#define set(a,v) 		        memset(a, v, sizeof(a))
#define clear(a)                memset(a, 0, sizeof(a))
#define least_first_heap(T)     priority_queue<T, deque<T>, std::greater<T> >
using namespace std;

typedef long long ll; typedef unsigned long long ull;
template<class T> bool inline between(const T& lb, const T& v, const T& ub) { return lb<=v && v<=ub; }
const int INF = 1E9+7;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	#endif

	int vec[4], tc;

	cin >> tc;
	while(tc--)
	{
        fup(i,0,4) scanf("%d", vec+i);
        sort(vec, vec+4);
        if( vec[0] == vec[3] )
            puts("square");
        else if( vec[0] == vec[1] && vec[2] == vec[3] )
            puts("rectangle");
        else if( ( ll(vec[0]) + ll(vec[1]) + ll(vec[2]) ) > vec[3] )
            puts("quadrangle");
        else
            puts("banana");
	}

    fclose(stdout);
    return 0;
}
