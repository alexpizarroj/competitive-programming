#include <cstdio>
#include <iostream>
using namespace std;

typedef long long Number;
const int cstMaxN = 500;
Number ans_dp[cstMaxN+10];
Number dp[cstMaxN+5][cstMaxN+5]; // [ H ] [ N ]; N = number of bricks, H = max height

void dp_precalc()
{
    // Base cases
    for(int N = 1; N <= cstMaxN; ++N) dp[0][N] = 0;
    for(int H = 0; H <= cstMaxN; ++H) dp[H][0] = 1;
    // Recurrences
    for(int H = 1; H <= cstMaxN; ++H)
    {
        for(int N = 1; N <= cstMaxN; ++N)
        {
            Number &value = dp[H][N];
            value = 0;
            for(int m = min(H, N), i = 1; i <= m; ++i)
            {
                value += dp[i - 1][N - i];
            }
        }
    }
}

void ans_dp_precalc()
{
    ans_dp[0] = ans_dp[1] = ans_dp[2] = 0;
    for(int N = 3; N <= cstMaxN; N++)
    {
        Number &value = ans_dp[N];
        value = 0;
        for(int i = N - 1; i >= 1; --i)
        {
            value += dp[i - 1][N - i];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    dp_precalc();
    ans_dp_precalc();

	int n;
	while ( scanf("%d", &n) != EOF )
	{
        //printf("%I64d\n", ans_dp[n]);
	    cout << ans_dp[n] << endl;
	}
    return 0;
}
