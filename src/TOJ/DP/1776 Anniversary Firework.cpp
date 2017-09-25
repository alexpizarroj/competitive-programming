#include <cstdio>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
#define fupi(i,a,b) for(int i = (a); (i) <= int(b); ++i)

double p[405][405]; // p(n,k) = prob. of n rockets done with at most k salvos

int main()
{
    double expected, sum;
    int N;
    
    fupi(k,1,400) p[0][k] = p[1][k] = 1;
    fupi(n,2,400) p[n][0] = p[n][1] = 0;
    p[0][0] = 1, p[1][0] = 0;
    fupi(n,2,400) fupi(k,2,400)
    {
        sum = 0;
        fup(le,0,n) sum += p[le][k-1]*p[n-1-le][k-1] - p[le][k-2]*p[n-1-le][k-2];
        p[n][k] = (1./n)*sum + p[n][k-1];
    }
        
    while ( ~scanf("%d", &N) ) 
    {
        expected = 0;
        fupi(k,1,400) expected += (p[N-2][k]-p[N-2][k-1]) * (k*10);
        printf("%.8lf\n", expected);
    }
	
    return 0;
}
