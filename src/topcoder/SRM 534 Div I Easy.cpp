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
#define INVALID                 -1
using namespace std;

typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii;
template<class T> bool inline between(const T& lb, const T& v, const T& ub) { return lb<=v && v<=ub; }
const int INF = int(1E9+7);

class EllysCheckers
{
public:
    EllysCheckers()
    {
        set(dp, INVALID);
        dp[0] = false;
    }

    string getWinner(string board)
    {
        int mask = 0;

        boardSize = board.size();
        for(int i = boardSize-1, j = 0; i >= 0; i--, j++)
        {
            if( board[j]=='o' )
            {
                mask |= (1<<i);
            }
        }
        mask = mask & (~1);

        return ( wins(mask) ? "YES" : "NO" );
    }

private:
    static const int BOARD_SIZE = 20;
    int dp[1<<BOARD_SIZE];
    char board[BOARD_SIZE+1];
    int boardSize;

    inline bool get(int mask, int i)
    {
        return (mask & (1<<i)) > 0;
    }

    bool wins(const int mask)
    {
        bool win = false;

        if( dp[mask] != INVALID )
        {
            win = dp[mask];
        }
        else
        {
            for(int i = boardSize-1; i >= 0; i--)
            {
                if( get(mask, i) ) // if there's a checker
                {
                    // can we move to the right?
                    if( i-1 >= 0 && !get(mask,i-1) )
                    {
                        int mask2 = ((mask & (~(1<<i))) | (1<<(i-1))) & (~1);
                        win = !wins(mask2);
                    }
                    // can we jump over other checkers?
                    if( !win && i-3 >= 0 && get(mask,i-1) && get(mask,i-2) && !get(mask,i-3) )
                    {
                        int mask2 = ((mask & (~(1<<i))) | (1<<(i-3))) & (~1);
                        win = !wins(mask2);
                    }
                }
            }
        }

        return (dp[mask] = win);
    }
};

EllysCheckers obj;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	#endif

    int tc;
    string board;

    cin >> tc; getchar();
    while( tc-- )
    {
        getline(cin, board);
        cout << obj.getWinner(board) << endl;
    }

    fclose(stdout);
    return 0;
}
