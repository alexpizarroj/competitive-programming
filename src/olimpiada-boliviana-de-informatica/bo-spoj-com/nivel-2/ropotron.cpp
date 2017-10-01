#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int n, nc, q, x, sum, cnt;
	vector<int> coins, precalc;
	vector<bool> possible;

    scanf("%d", &nc);
	for(int caseNo = 1; caseNo <= nc; caseNo++)
    {
        // Input
        scanf("%d", &n);
        coins.resize(n); sum = 0;
        for(int i = 0; i < n; i++) scanf("%d", &coins[i]), sum += coins[i];

        // Process
        precalc = vector<int>(n+1, 0), precalc[0] = 1;
        possible = vector<bool>(sum+1, false), possible[0] = true;
        cnt = 1;
        for(int k = 0; k < n; k++)
        {
            for(int i = sum; i >= coins[k]; i--)
                if ( !possible[i] && possible[i-coins[k]] )
                    possible[i] = true, cnt++;
            precalc[k+1] = cnt;
        }

        // Output
        printf("Caso %d:\n", caseNo);
        scanf("%d", &q);
        while ( q-- )
        {
            scanf("%d", &x);
            printf("%d\n", precalc[x]);
        }
    }

    return 0;
}
