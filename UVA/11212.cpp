#include <ctime>
#include <cassert>
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
#include <numeric>

#define pb              push_back
#define all(a)          (a).begin(), (a).end()
#define forn(i, n)      for(int i = 0; i < int(n); ++i)
#define fore(i, a, b)   for(int i = int(a); i <= int(b); ++i)
#define foreach(it, a)  for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)

using namespace std;

const int inf = int(1e9+7);
typedef pair<int,int>   ii;
typedef vector<int>     vi;
typedef long long       i64;
typedef vector<i64>     vi64;

const int MXSZ = 9, DEPTH = 5, TH = DEPTH/2;
const int pwr[] = { 1, 10, 100, (int)1e3, (int)1e4, (int)1e5, (int)1e6,
                   (int)1e7, (int)1e8, (int)1e9 };

int operate(int state, int cuts, int cute, int p)
{
    int le, ri, mid;
    ri = state % pwr[MXSZ-cute-1];
    le = state / pwr[MXSZ-cuts];
    mid = (state / pwr[MXSZ-cute-1]) % pwr[cute-cuts+1];
    
    int next = le*pwr[MXSZ-cute-1] + ri, sz = MXSZ - (cute-cuts+1);
    le = next / pwr[sz-p];
    ri = next % pwr[sz-p];
    next = (le*pwr[cute-cuts+1] + mid)*pwr[sz-p] + ri;
    
    return next;
}

void bfs(int start, map<int,int> &dist)
{
    queue<int> q; q.push(start);
    dist.clear(); dist[start] = 0;
    while ( !q.empty())
    {
        int cur = q.front(); q.pop();
        int curdist = dist[cur];
        forn(i,MXSZ) fore(j,i,MXSZ-1) forn(k,MXSZ-j+i)
        {
            int next = operate(cur, i, j, k);
            if ( dist.count(next) == 0 )
            {
                dist[next] = curdist + 1;
                if ( curdist+1 < TH ) q.push(next);
            }
        }
    }
}

int main()
{
    //size_t startt = clock();
    
    map<int,int> ridist;
    bfs(123456789, ridist);
       
    int n, caseno = 1;
    while ( scanf("%d", &n), n )
    {
        int start = 0, offset = MXSZ - n;
        forn(i,offset)
        {
            start = 10*start + (i+1);
        }
        forn(i,n)
        {
            int value;
            scanf("%d", &value);
            start = 10*start + (value + offset);
        }
        //cerr << "Starting permutation is " << start << endl;
        
        int ans = inf;
        if ( ridist.count(start) == 0 )
        {
            map<int,int> ledist;
            bool found = false;
            bfs(start, ledist);
            for(auto it : ledist)
            {
                int state = it.first;
                if ( ridist.count(state) > 0 )
                {
                    found = true;
                    ans = min(ans, ledist[state] + ridist[state]);
                }
            }
            if ( !found ) ans = DEPTH;
        }
        else 
        {
            ans = ridist[start];
        }
        printf("Case %d: %d\n", caseno++, ans);
    }
    
    //size_t endt = clock();
    //cerr << "Running Time is " << double(endt-startt)/CLK_TCK << "\n";
    
    return 0;
}