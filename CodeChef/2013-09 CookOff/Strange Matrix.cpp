#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int f(int n, int m)
{
    if( n < m )
        return f(m, n);
    else if ( n == m || m == 1 )
        return n;
    else
    {
        if ( (n-m)%(m-1) == 0 )
            return m;
        else
        {
            int q = int((n-m)/(m-1)) * (m-1);
            return f(m, n - m - q + 1);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t, n, m;
	scanf("%d", &t);
	while (t--)
	{
        scanf("%d %d", &n, &m);
        printf("%d\n", f(n,m));
	}
    return 0;
}
