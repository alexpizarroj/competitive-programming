// UVA 10209 - Is This Integration?
// http://tinyurl.com/phhgtrh
#include <cstdio>
#include <cmath>

int main()
{
    double a, r1, r2, r3;
    
    while ( ~scanf("%lf", &a) )
    {
        r3 = (4. - sqrt(3) - (2./3.)*acos(-1))*(a*a);
        r2 = (a*a) * (4. - acos(-1)) - (2*r3);
        r1 = (a*a) - r2 - r3;
        printf("%.3lf %.3lf %.3lf\n", r1, r2, r3);
    }
	
    return 0;
}
