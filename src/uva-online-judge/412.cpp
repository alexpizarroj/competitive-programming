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
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define PB push_back
#define MP make_pair
#define PI acos(-1)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define range(v) (v).begin(), (v).end()
#define len(a) (int)(a).length()
#define sz(a) (int)(a).size()
#define sqr(a) (a)*(a)
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


int gcd(int a, int b)
{
    if( a<b ) swap(a,b);

    if( b == 0 ) return a;
    else         return gcd(b, a%b);
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

	int n,i,j;
	int cnt, total;
    vector<int> v;

    while( scanf("%d", &n), n != 0 )
    {
        v.resize(n);
        FOR(i,n) scanf("%d", &v[i]);

        cnt = total = 0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if( gcd(v[i],v[j]) == 1 ) cnt++;
                total++;
            }
        }

        if( cnt==0 )
            puts("No estimate for this data set.");
        else
        {
            double pi = sqrt((6.*total)/cnt);
            printf("%.6lf\n", pi);
        }
    }

    return 0;
}
