#include <cstdio>
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t, n;
	int vec[60][4];
	double ans;
	scanf("%d", &t);
	while ( t-- )
	{
	    scanf("%d", &n);
	    fup(i,0,n)
	    {
	        scanf("%d %d %d", &vec[i][2], &vec[i][0], &vec[i][1]);
	        vec[i][3] = 100 - vec[i][2];
	    }
	    ans = 0;
	    if ( n <= 16 )
	    {
            for(int lim = 1<<n, mask = 0; mask < lim; mask++)
            {
                bool valid = true;
                for(int i = 0; i < n && valid; i++)
                {
                    for(int j = 0; j < n && valid; j++)
                    {
                        if ( i == j ) continue;
                        if ( vec[i][bool(mask&(1<<i))] == vec[j][bool(mask&(1<<j))] )
                        {
                            valid = false;
                        }
                    }
                }
                if ( valid )
                {
                    double prob = 1;
                    fup(i,0,n)
                    {
                        prob *= double(vec[i][ bool(mask&(1<<i))+2 ])/100;
                    }
                    ans += prob;
                }
            }
	    }
	    printf("%.8lf\n", ans);
	}
    return 0;
}
