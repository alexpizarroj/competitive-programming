#include <iostream>
using namespace std;
typedef long long i64;
const int inf = int(1e9+7);

i64 modexp(int b, int e)
{
	if ( e == 0 )
		return 1;
	else
	{
		i64 ans = modexp(b, e/2);
		return (ans * ans % inf) * (e&1 ? b : 1) % inf;
	}
}

int main()
{
    int tc;
	cin >> tc;
	while ( tc-- )
	{
		int n;
		cin >> n;
		cout << ( n == 1 ? 1 : modexp(2,n-2) * (n+1) % inf) << "\n";
	}
    return 0;
}
