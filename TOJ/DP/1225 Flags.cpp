#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned int Number;

Number getNth(int n)
{
    if ( n < 2 ) return 2;
    Number a, b, aux;
    a = b = 2;
    for(int i = 3; i <= n; i++)
    {
        aux = a+b, a = b, b = aux;
    }
    return b;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int n;
	while ( scanf("%d", &n) != EOF )
	{
	    printf("%u\n", getNth(n));
	}
    return 0;
}
