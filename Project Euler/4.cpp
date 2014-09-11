#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

bool palin(int n)
{
    int a = n, m = 0;
    while ( a > 0 )
    {
        m = 10*m + a%10;
        a /= 10;
    }
    return (n == m);
}

int main()
{
    const int lo = 100, hi = 999;
    int ans = 0, cand;
    
    for(int i = lo; i <= hi; i++) for(int j = i; j <= hi; j++)
    {
        cand = i * j;
        if ( cand > ans && palin(cand) ) ans = cand;
    }
    cout << ans << endl;
	
    return 0;
}
