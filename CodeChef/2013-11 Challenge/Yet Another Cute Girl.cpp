#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <bitset>
#include <cmath>
using namespace std;

typedef long long Number;
const int cstPrimesUBound = int(1e6);
vector<int> primelst;
bitset<cstPrimesUBound+5> prime, valid;

void sieve(int ubound)
{
    prime.set();
    primelst.clear();
    prime[0] = prime[1] = false;
    for(int i = 2; i*i <= ubound; ++i)
    {
        if ( !prime[i] ) continue;
        for(int j = i*i; j <= ubound; j += i) prime[j] = false;
    }
    for(int i = 2; i <= ubound; ++i)
    {
        if ( prime[i] ) primelst.push_back(i);
    }
}

int main()
{
    int tc, ans, start;
    Number l, r, offset, ubound;
    
    sieve(cstPrimesUBound);
    scanf("%d", &tc);
    while ( tc-- )
    {
        cin >> l >> r;
        offset = l, ubound = r;
        l -= offset, r -= offset;
        
        valid.set();
        if ( offset == 1 ) valid[0] = false;
        for(int i=0, cp=primelst[i]; i < (int)primelst.size();
            ++i, cp=primelst[i])
        {
            // Composite numbers marking
            start = (cp - (offset%cp))%cp;
            for(int j = start+( offset+start == cp ? cp : 0);
                j <= r; j += cp)
            {
                valid[j] = false;
            }
            // Fix of valid pairs
            start = max( (int)ceil( (double)log(offset)/log(cp) ), 1 );
            for(Number j = pow(cp, start); j <= ubound; j*=cp, ++start)
            {
                if ( prime[start+1] ) valid[j-offset] = true;
            }
        }
        
        ans = 0;
        for(int i = l; i <= r; ++i) if ( valid[i] ) ++ans;
        printf("%d\n", ans);
    }
    
    return 0;
}
