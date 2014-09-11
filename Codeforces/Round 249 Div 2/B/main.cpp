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
typedef vector<ii>      vii;
typedef long long       i64;
typedef vector<i64>     vi64;


int main()
{
    char a[20]; int n;
    while ( scanf("%s %d", a, &n) != EOF )
    {
        int start = 0, len = strlen(a);
        while ( n > 0 && start < len )
        {
            // Can we improve our left most digit?
            int top = min(n+1, len-start);
            int mx = *max_element(a+start, a+start+top);
            if ( a[start] == mx ) { ++start; continue; }
            // If so, get the pos of the improvement
            int mxpos;
            fore(i,start,start+top-1)
            {
                if ( a[i] == mx )
                {
                    mxpos = i;
                    break;
                }
            }
            //printf("Improving (%c,%d) to (%c,%d)\n", a[start], start, a[mxpos], mxpos);
            // Bring the best here
            for(int i = mxpos; i >= start+1; i--)
            {
                swap(a[i], a[i-1]);
                --n;
            }
            // Jump next
            ++start;
        }
        printf("%s\n", a);
    }
    return 0;
}
