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
#define all(a)		 	        (a).begin(), (a).end()
#define set(a,v) 		        memset(a, v, sizeof(a))
#define clr(a)                memset(a, 0, sizeof(a))
#define least_first_heap(T)     priority_queue<T, deque<T>, std::greater<T> >
using namespace std;

typedef long long ll; typedef unsigned long long ull;
template<class T> bool inline between(const T& lb, const T& v, const T& ub) { return lb<=v && v<=ub; }
const int INF = int(1E9+7);

class BadNeighbors
{
public:
	int maxDonations(vector <int> donations)
	{
		return max( calcMaxDonations(donations, 0), calcMaxDonations(donations, 1) );
	}

private:
	int mx[40];
	inline int gpos(int start, int n, int var) { return (start+var)%n; }

	int calcMaxDonations(const vector<int>& vec, int start)
	{
		int best, i, j;
		int n = vec.size();

		if( n <= 3 )
			best = *max_element( all(vec) );
		else
		{
			best = 0;
			mx[0] = vec[start];
			mx[1] = vec[gpos(start,n,1)];

			for(i=2, j=0; i<n; i++, j++)
			{
				best = max(best, mx[j]);
				mx[i] = vec[gpos(start,n,i)] + best;
			}

			//fup(i,0,n) printf("%2d ", mx[i]); cout << endl;
			best = max( mx[n-2], mx[n-3] );
		}

		return best;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	#endif

	vector<int> vec;
	BadNeighbors obj;
	int n, best;

	while ( scanf("%d", &n) != EOF )
	{
		vec.resize(n);
	    fup(i,0,n) scanf("%d", &vec[i]);
		best = obj.maxDonations(vec);
	    printf("%d\n", best );
	}

    fclose(stdout);
    return 0;
}
