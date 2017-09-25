#include <cstdio>
#include <cmath>
int v[100010];

bool isPrime(int n)
{
	if ( n < 2 ) return false;
	if ( n != 2 && n%2 == 0 ) return false;
	for(int lim = (int)floor(sqrt(n)), i = 3; i <= lim; i+=2)
		if ( n%i == 0 )
			return false;
	return true;
}

int main()
{
    int n;
	while ( scanf("%d", &n) != EOF )
	{
		for(int i = 0; i < n; i++)
			scanf("%d", v+i);
		int q;
		scanf("%d", &q);
		bool ans = false;
		for(int i = 0; i < n; i++)
			if ( v[i] == q )
			{
				if ( i>0 && i+1<n && isPrime(v[i-1]) && isPrime(v[i+1]))
					ans = true;
				break;
			}
		puts(ans ? "Yes" : "No");
	}
    return 0;
}
