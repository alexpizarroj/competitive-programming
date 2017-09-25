#include <iostream>
#include <string>
using namespace std;

int fib[46];

inline int f(int n) { return fib[n+2]; }

string g(int k, int n)
{
    if ( n == 0 )          return "";
    else if ( n == 1 )     return string(1,(k-1)+'0');
    else if ( k <= f(n-1)) return "0" + g(k, n-1);
    return "10" + g(k-f(n-1), n-2);
}

int main()
{
    int n, k;
    
    fib[0] = 0, fib[1] = 1;
    for(int i=2; i<=45; ++i) fib[i] = fib[i-1] + fib[i-2];
    while ( cin >> n >> k ) cout << ( k > f(n) ? "-1" : g(k, n) ) << endl;
	
    return 0;
}
