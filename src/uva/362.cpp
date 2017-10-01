// includes {
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
// }
using namespace std;
// defines {
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define TOK(pc, s, tokens) for(char* pc = strtok(s, tokens); pc != NULL; pc = strtok(NULL,tokens))
#define SZ(a) (int)(a).size()
#define LEN(a) (int)(a).length()
#define PB push_back
#define MP make_pair
#define all(a) (a).begin(), (a).end()
#define sqr(a) (a)*(a)
#define inrange(lb,i,ub) ((lb) <= (i) && (i) <= (ub))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// }
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};


int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

	ull bytes, transfered, received, rate;
	int time, dataSet=1;

	while( scanf("%llu", &bytes), bytes > 0 )
	{
	    printf("Output for data set %d, %llu bytes:\n", dataSet++, bytes);

	    transfered = time = rate = 0;
        while( transfered < bytes )
        {
            scanf("%llu", &received);
            transfered += received, rate += received;
            time++;

            if( time%5==0 )
            {
                printf("   Time remaining: ");
                if( rate > 0 )
                    printf("%d seconds\n", int(ceil((5*(bytes-transfered))/(double)rate)) );
                else
                    printf("stalled\n");
                rate = 0;
            }
        }

        printf("Total time: %d seconds\n\n", time);
	}

    return 0;
}
