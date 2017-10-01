#include <cstdio>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)

void f(int vec[], int n)
{
    if ( n == 1 )
    {
        vec[0] = 1;
    }
    else if ( n == 2 )
    {
        vec[0] = 3, vec[1] = 4;
    }
    else if ( n%2 == 0 )
    {
        fup(i,0,n-1) vec[i] = 1;
        vec[n-1] = (n-2)/2;
    }
    else
    {
        fup(i,0,n-2) vec[i] = 1;
        vec[n-2] = 2;
        vec[n-1] = (n+1)/2;
    }
}

int main()
{
    int n, m, a[105], b[105];
    
    while ( scanf("%d %d", &n, &m) != EOF )
    {
        f(a,n), f(b,m);
        fup(i,0,n)
        {
            fup(j,0,m) printf("%d ", a[i]*b[j]);
            puts("");
        }
    }
	
    return 0;
}
