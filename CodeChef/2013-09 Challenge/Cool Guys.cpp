#include <cstdio>
#include <cmath>
#define MAX 31622
typedef long long Num;

Num gcd(Num a, Num b)
{
    Num r;
    while ( b != 0 )
    {
        r = a%b, a = b, b = r;
    }
    return a;
}

Num count(int n)
{
    int u = sqrt(n);
    Num sum = 0;
    for(int i = 1; i <= u; i++)
    {
        sum += (n/i);
    }
    return 2*sum - u*u;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	Num a, b, g;
	scanf("%d", &t);
	while ( t-- )
	{
	    scanf("%d", &n);
	    a = count(n), b = Num(n)*n;
	    g = gcd(a,b);
	    a /= g, b /= g;
	    printf("%lld/%lld\n", a, b);
	}
    return 0;
}
