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

int main()
{
    int n, n2, k;
    const int offset = 600000000;
    
    while ( ~scanf("%d %d", &n, &k) )
    {
        if ( (n==1 && k!=0) || (k==0 && n>1) ) 
        {
            puts("-1");
        }
        else if ( n == 1 || k == 0 )
        {
            puts("1");
        }
        else if ( k < (n/2) )
        {
            puts("-1");
        }
        else
        {
            int value = offset;
            
            n2 = (n/2);
            fup(i,1,n2)
            {
                if ( i > 1 ) printf(" ");
                printf("%d %d", value, value+1);
                value += 2;
            }
            if ( n2 > 1 ) printf(" ");
            k -= (n2-1);
            printf("%d %d", k, k*2);
            if ( n&1 ) printf(" %d", value);
            puts(" ");
        }
    }
	
    return 0;
}
