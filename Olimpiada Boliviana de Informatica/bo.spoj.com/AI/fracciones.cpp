#include <cstdio>

int gcd(int a, int b)
{
	int c;
	while (b != 0)
		c = a%b, a = b, b = c;
	return a;
}

int main()
{
    int n, bob, alice;
	while ( scanf("%d", &n), n > 0 )
	{
		int nu, de;
		bob = alice = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d/%d", &nu, &de);
			if ( gcd(nu,de) == 1 )
				++alice;
		}
		for(int i = 0; i < n; i++)
		{
			scanf("%d/%d", &nu, &de);
			if ( gcd(nu,de) == 1 )
				++bob;
		}
		if ( bob > alice )
			puts("Bob");
		else if ( alice > bob )
			puts("Alice");
		else
			puts("=");
	}
    return 0;
}
