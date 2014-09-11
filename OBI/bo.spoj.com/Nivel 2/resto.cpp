#include <cstdio>
using namespace std;

int M;

inline void mult(int a, int b, int c, int d, int e, int f, int g, int h, int &a11, int &a12, int &a21, int &a22)
{
    a11 = (a*e + b*g)%M, a12 = (a*f + b*h)%M;
    a21 = (c*e + d*g)%M, a22 = (c*f + d*h)%M;
}

void matModExp(int &a, int &b, int &c, int &d, int n)
{
    if ( n == 1 ) // base case
    {
        a = 0, b = c = d = 1;
    }
    else if ( n%2 == 0 ) // if even
    {
        matModExp(a,b,c,d,n/2);
        mult(a,b,c,d, a,b,c,d, a,b,c,d);
    }
    else // if odd
    {
        matModExp(a,b,c,d,(n-1)/2);
        mult(a,b,c,d, a,b,c,d, a,b,c,d);
        mult(a,b,c,d, 0,1,1,1, a,b,c,d);
    }
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int x, a, b, c, d;
	while ( scanf("%d %d", &M, &x), M || x )
	{
	    matModExp(a,b,c,d,x+1);
	    printf("%d\n", b);
	}

    return 0;
}
