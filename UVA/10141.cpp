#include <cstdio>
#include <cstring>
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	#endif

	char bf[100], best[100];
	int bestComp, comp;
	double bestPrice, price;
    int n, p, rfp = 1;

	while ( scanf("%d %d", &n, &p), getchar(), (n || p) )
	{
	    if( rfp > 1 ) puts("");

        fup(i,0,n) gets(bf);
        bestComp = 0;
        fup(i,0,p)
        {
            gets(bf);
            scanf("%lf %d", &price, &comp); getchar();
            if( comp > bestComp )
            {
                strcpy(best, bf);
                bestComp = comp;
                bestPrice = price;
            }
            else if ( comp == bestComp && price < bestPrice )
            {
                strcpy(best, bf);
                bestPrice = price;
            }
            fup(j,0,comp) gets(bf);
        }
        printf("RFP #%d\n%s\n", rfp++, best);
	}

    return 0;
}
