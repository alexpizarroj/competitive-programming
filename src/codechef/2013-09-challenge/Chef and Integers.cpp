#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define PB 				        push_back
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
using namespace std;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int n, idx, x, var;
    ull cost;
    vector<int> vec;
    while ( scanf("%d", &n) != EOF )
    {
        vec.clear();
        fup(i,0,n)
        {
            int val;
            scanf("%d", &val);
            vec.PB(val);
        }
        scanf("%d", &x);

        sort(vec.begin(),vec.end(), greater<int>());
        idx = distance(vec.begin(), upper_bound(vec.begin(),vec.end(),0,greater<int>()));
        cost = 0, var = 0;
        fup(i,idx,n)
        {
            if ( vec[i]+var == 0 ) continue;
            cost += ull(abs(vec[i] + var)) * min(n-i,x);
            var = (-vec[i]);
        }
        printf("%lld\n", cost);
    }
    return 0;
}
