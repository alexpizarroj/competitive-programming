#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#define fup(i,a,b) for(int i = (a); (i) < int(b); i++)
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n, k, v;
    long long cost;
	map<int, int> mp;

	while ( scanf("%d", &n), n )
	{
	    cost = 0;
	    mp.clear();

	    fup(i,0,n)
	    {
	        scanf("%d", &k);
	        fup(j,0,k)
	        {
	            scanf("%d", &v);
	            if ( mp.count(v) == 0 )
                    mp[v] = 1;
                else
                    mp[v]++;
	        }

            cost += mp.rbegin()->first - mp.begin()->first;
            if ( mp.begin()->second == 1 ) mp.erase(mp.begin()); else --(mp.begin()->second);
            if ( mp.rbegin()->second == 1 ) mp.erase(mp.rbegin()->first); else --(mp.rbegin()->second);
	    }

        printf("%lld\n", cost);
	}

    return 0;
}

