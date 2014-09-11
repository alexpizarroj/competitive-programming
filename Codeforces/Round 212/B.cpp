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
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define MSB(n) ( n <= 0 ? 0 : int(floor(log(n)/log(2))) )
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

    vector<int> d;
    int n, m, s;
    bool yes;

    while ( cin >> n >> m )
    {
        d.clear();
        fup(i,0,m)
        {
            cin >> s;
            d.PB(s);
        }

        yes = true;
        sort(d.begin(), d.end());
        if ( d.size() > 0 && (d.front() == 1 || d.back() == n ) ) yes = false;
        if ( yes )
        {
            int lim = d.size() - 2;
            fup(i,0,lim)
            {
                if ( (d[i]+1 == d[i+1]) && ( d[i+1]+1 == d[i+2] ) ) yes = false;
            }
        }
        puts(yes ? "YES" : "NO");
    }

    return 0;
}
