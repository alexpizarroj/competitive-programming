#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int tc, n, start, k, bestTot;
    map<int, int> mp;
    
    scanf("%d", &tc);
    while ( tc-- )    
    {
        mp.clear();
        bestTot = 0, start = 1;
        
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &k);
            if( mp.count(k) == 1 && mp[k] >= start )
            {
                bestTot = max(bestTot, i-start);
                start = mp[k] + 1;
            }
            mp[k] = i;
        }
        bestTot = max(bestTot, n-start+1);
        
        printf("%d\n", bestTot);
    }
    
    return 0;
}