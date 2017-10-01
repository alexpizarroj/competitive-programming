// IO
#include <iostream>
#include <cstdio>
// STL
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;
// STRINGS
#include <string>
#include <cstring>
// OTROS
#include <cstdlib>
#include <memory.h>
#include <cmath>
// MACROS
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()


int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    #endif

    int n, cmd, x, val, i;
    bool bs, bq, bpq;
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;

    while ( scanf("%d", &n) != EOF )
    {
        while( !s.empty() ) s.pop();
        while( !q.empty() ) q.pop();
        while( !pq.empty() ) pq.pop();
        bs = bq = bpq = true;

        for(i=0; i<n; i++)
        {
            scanf("%d %d", &cmd, &x);
            if( cmd == 1 )
            {
                if( bs  ) s.push(x);
                if( bq  ) q.push(x);
                if( bpq ) pq.push(x);
            }
            else
            {
                if( bs )
                {
                    val = -1;
                    if( !s.empty() )
                    {
                        val = s.top();
                        s.pop();
                    }
                    if( val != x ) bs = false;
                }
                if( bq )
                {
                    val = -1;
                    if( !q.empty() )
                    {
                        val = q.front();
                        q.pop();
                    }
                    if( val != x ) bq = false;
                }
                if( bpq )
                {
                    val = -1;
                    if( !pq.empty() )
                    {
                        val = pq.top();
                        pq.pop();
                    }
                    if( val != x ) bpq = false;

                }
            }
        }

        if( bq + bs + bpq > 1 )
            puts("not sure");
        else if ( bs )
            puts("stack");
        else if ( bq )
            puts("queue");
        else if ( bpq )
            puts("priority queue");
        else
            puts("impossible");
    }

    return 0;
}

