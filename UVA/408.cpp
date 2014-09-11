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

#define MAX 10000000
bool used[MAX];

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int step,mod,i,seed;
    int cnt;

    while( scanf("%d %d", &step, &mod) != EOF )
    {
        cnt=mod;
        SET(used,false);

        seed=0;
        used[seed]=true;
        cnt--;
        REP(i,mod)
        {
            seed=(seed+step)%mod;
            if( !used[seed] )
            {
                used[seed]=true;
                cnt--;
            }
        }
        printf("%10d%10d    %s\n\n", step,mod, (cnt==0 ? "Good Choice" : "Bad Choice"));
    }


    return 0;
}
