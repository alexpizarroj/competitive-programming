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

double r[101][2]; // col. distribution: car's value, debt
double depr[101];

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	#endif

	int duration, nRecords, month;
	double downPay, debt, payment, p;

    while ( scanf("%d", &duration), duration >= 0 )
    {
        // Input reading
        scanf("%lf %lf %d", &downPay, &debt, &nRecords);
        dset(depr, 0);
        fup(i,0,nRecords)
        {
            scanf("%d %lf", &month, &p);
            depr[month] = p;
        }

        // Processing
        payment = debt / duration;
        p = depr[0];
        r[0][0] = (downPay + debt) * (1-p);
        r[0][1] = debt;
        for(int i = 1; i <= duration; i++)
        {
            if( depr[i] > 0 ) p = depr[i];
            r[i][0] = r[i-1][0] * (1-p);
            r[i][1] = r[i-1][1] - payment;
        }

        // Output
        for(int i = 0; i <= duration; i++)
        {
            if( r[i][1] < r[i][0] )
            {
                printf("%d ", i);
                puts(i == 1 ? "month" : "months");
                break;
            }
        }
    }

    return 0;
}
