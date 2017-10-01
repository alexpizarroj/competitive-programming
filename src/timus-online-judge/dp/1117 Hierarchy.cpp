#include <iostream>
using namespace std;

int f(int a)
{
    int ret = 0;
    while ( (a&1)==0 ) ++ret, a>>=1;
    return max(ret-1,0);
}

int cost(int x, int y)
{
    if ( y < x ) return cost(y, x);
    else if ( x == y ) return 0;
    
    int ans = 0, pwr = 4;
    for(int i = 2; i <= 30; i++, pwr<<=1) ans += y/pwr - (x-1)/pwr;
    ans = 2*ans - f(x) - f(y);
    return ans;
}

int main()
{
    int x, y;
    
    while ( cin >> x >> y, cin ) cout << cost(x,y) << endl;
    return 0;
}
