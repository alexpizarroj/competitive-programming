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
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)
#define ftok(pc, str, delim) for(char *pc = strtok(str, delim); pc != NULL; pc = strtok(NULL, delim))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); ++it)
#define rforeach(it, a) for(typeof((a).rbegin()) it=(a).rbegin(); it != (a).rend(); ++it)
using namespace std;
const int INF = int(1e9+7);
const double EPS = 1e-6;
typedef pair<int,int> ii;
typedef vector<int> vi;

int suba[205][205][205], suma[205];

int nextmax(int *a1, int *a2, int &n1, int &n2)
{
    if ( !n1 && !n2 ) return -INF;
    int ans, val1, val2;
    val1 = (n1 > 0 ? a1[n1-1] : -INF);
    val2 = (n2 > 0 ? a2[n2-1] : -INF);
    if ( val1 > val2 )  { --n1, ans = a1[n1]; }
    else                { --n2, ans = a2[n2]; }
    
    return ans;
}

int main()
{
    vi a;
    int n, shift, ans;
    while ( cin >> n >> shift )
    {
        a.resize(n), suma[0] = 0;
        fup(i,0,n) cin >> a[i];
        
        fup(i,0,n) suma[i+1] = suma[i] + a[i];
        fup(i,0,n) fup(j,i,n)
        {
            fupi(k,i,j) suba[i][j][k-i] = a[k];
            sort(suba[i][j], suba[i][j]+(j-i+1));
        }
        ans = -INF;
        fup(i,0,n) fup(j,i,n)
        {
            int sum = suma[j+1]-suma[i], len = j-i+1, *vec;
            int *le, lelen, *ri, rilen, val, rem = shift, k = 0;
            vec = suba[i][j], lelen = i, rilen = (n-j-1);
            le = (lelen ? suba[0][i-1]   : NULL);
            ri = (rilen ? suba[j+1][n-1] : NULL);
            while (rem && k < len && (val = nextmax(le,ri,lelen,rilen)) > vec[k])
            {
                sum += -vec[k] + val;
                --rem, ++k;
            }
            if ( sum > ans ) ans = sum;
        }
        
        cout << ans << endl;
    }
	
    return 0;
}
