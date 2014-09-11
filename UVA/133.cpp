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
#define PB 				        push_back
#define F                       first
#define S                       second
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define dall(a)		 	        (a).begin(), (a).end()
#define dinit(a) 		        memset(a, -1, sizeof(a))
#define dclr(a)         	 	memset(a, 0, sizeof(a))
#define dbet(lb,v,ub)			(lb <= v && v <= ub)
using namespace std; const int INF = int(1E9+7);
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> ii; typedef vector<int> vi;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

    long long p;
    long double lp, lpp, t, c = logl(10)/logl(2);

    while ( cin >> p )
    {
        lp = logl(p)/logl(2), lpp = logl(p+1)/logl(2);
        t = floorl(log10l(p))+2;
        while ( ceill(lp+t*c) != floor(lpp+t*c) ) t++;
        cout << ll(lpp+t*c) << endl;
    }

    return 0;
}
