#include <cstdio>
#define MAX 30000
#define ull unsigned long long
ull ans[MAX+1];


int main() {
    int coin[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
    int i,j; double t;

    ans[0] = 1;
    for(i=0; i<11; i++)
        for(j=coin[i]; j<=MAX; j+=5)
            ans[j] += ans[j-coin[i]];

    while( true ) {
        scanf("%lf",&t); if( t==0 ) break;
        i = itn(t*100+0.5);
        printf("%6.2lf%17llu\n",t,ans[i]);
    }

    return 0;
}
