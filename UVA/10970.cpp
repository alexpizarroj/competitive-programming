#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    int M,N;
    while( scanf("%d %d", &M, &N) == 2 )
        printf("%d\n", min( (M-1) + (N-1)*M, (N-1) + (M-1)*N ) );

    return 0;
}
