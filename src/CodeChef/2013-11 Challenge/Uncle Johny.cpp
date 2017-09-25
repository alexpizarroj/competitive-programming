#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int tc, n, k, prevValue;
    vector<int> v;
    
    scanf("%d", &tc);
    while ( tc-- )
    {
        scanf("%d", &n); v.resize(n);
        for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
        scanf("%d", &k); k = v[k-1];
        sort(v.begin(), v.end());
        printf("%d\n", distance(v.begin(), lower_bound(v.begin(), v.end(), k)) + 1);
    }

    return 0;
}
