#include <iostream>
#include <cstdio>
using namespace std;
typedef long long Number;

int fibMod(Number n, const int M)
{
    if ( n <= 0 ) return 0;

    Number a, b, c, d, aux;
    a = 1, b = 0;
    c = 0, d = 1;
    --n;

    while ( n > 0 )
    {
        if ( n&1 )
        {
            aux = ( (d*b) + (c*a) )%M;
            b = ( d*(b+a) + (c*b) )%M;
            a = aux;
        }

        aux = ( c*c + d*d )%M;
        d = ( d * (2*c + d) )%M;
        c = aux;

        n = n/2;
    }

    return (a + b)%M;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

    Number n;
    int b, result, caseNo = 0;

    while ( scanf("%lld %d", &n, &b), (n || b) ) // cin >> n >> b
    {
        result = ( (2 * fibMod(n+1, b)) - 1 + b ) % b;
        printf("Case %d: %lld %d %d\n", ++caseNo, n, b, result);
        //cout << "Case " << (++caseNo) << ": " << n << " " << b << " " << result << endl;
    }

    return 0;
}
