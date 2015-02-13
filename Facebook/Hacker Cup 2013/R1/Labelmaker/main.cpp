#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
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
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;
const int INF = int(1E9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

bool will_overflow(long long n, long long mult)
{
    return mult > (LLONG_MAX/n);
}

int main()
{
    int t, len, nLetters;
    long long m, n, start, span;
    string l, ans;
    
    cin >> t;
    fupi(nCase, 1, t)
    {
        cin >> l >> m;
        len = l.size();
        
        n = m, nLetters = 1;
        start = 0, span = len;
        while ( n > span )
        {
            start += span;
            n -= span;
            ++nLetters;
            //cout << span << " * " << len << " will overflow? ";
            //cout << will_overflow(span,len) << endl;
            if ( will_overflow(span, len) ) break;
            span *= len;
        }
        assert(start+n == m);
        
        n -= 1;
        ans.resize(nLetters);
        for(int i = ans.size()-1; i >= 0; i--)
        {
            ans[i] = l[n%len];
            n /= len;
        }
        assert(n == 0);
        
        cout << "Case #" << nCase << ": " << ans << endl;
    }
	
    return 0;
}
