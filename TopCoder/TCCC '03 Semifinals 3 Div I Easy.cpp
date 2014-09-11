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

#define UP 0
#define DOWN 1
class ZigZag
{
public:
    int longestZigZag(vector<int> sequence)
    {
        int best = 1;
        vector< vector<int> > dp(2, vector<int>(sequence.size(), 1) );

        fup( idx,1,sequence.size() )
        {
            // if going up
            dp[UP][idx] = max_greater_than(idx, sequence, dp[DOWN]) + 1;

            // if going down
            dp[DOWN][idx] = max_less_than(idx, sequence, dp[UP]) + 1;

            // update
            best = max( max(best, dp[UP][idx]), dp[DOWN][idx]);
        }

        return best;
    }
private:
    int max_less_than(int u, const vector<int>& sequence, const vector<int>& vec)
    {
        int bestVal = 0;
        fup(i,0,u)
        {
            if( sequence[i] < sequence[u] && vec[i] > bestVal )
            {
                bestVal = vec[i];
            }
        }
        return bestVal;
    }

    int max_greater_than(int u, const vector<int>& sequence, const vector<int>& vec)
    {
        int bestVal = 0;
        fup(i,0,u)
        {
            if( sequence[i] > sequence[u] && vec[i] > bestVal )
            {
                bestVal = vec[i];
            }
        }
        return bestVal;
    }
};

int main() {
	#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	#endif

	ZigZag obj;
	int data[] = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
        600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
        67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
        477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
        249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
    vector<int> vec( data, data + sizeof(data)/sizeof(int) );

    cout << obj.longestZigZag(vec) << endl;

    fclose(stdout);
    return 0;
}
