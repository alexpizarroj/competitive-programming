#include <cstdio>
#include <vector>
using namespace std;

int n(int x) { return (x*(x+1))/2; }

int m(int x) { return ( x&1 ? x-3 : x-2); }

int f(int x)
{
    int sum = 0, val;
    for(int k = x-1; k >= 1; k--)
    {
        val = n(k); // amount of triangles of side (x-k+1) looking 'up'
        sum += val * ( 1 + m(x-k+1) );
    }
    for(int top = (x/2+1), k = 2; k <= top; k++)
    {
        val = n( x - 2*(k-1) ); // amount of triangles of side k looking 'down'
        sum += val * ( 1 );
    }
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int x;
	while ( scanf("%d", &x), x > 0 ) printf("%d\n", f(x));
    return 0;
}
