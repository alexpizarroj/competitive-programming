#include <iostream>
#include <cstdio>
using namespace std;

const int inf = int(1e9) + 7;
const int kMax = int(1e5);
int dp[kMax+5], sum[kMax+5];

int main()
{
	int tc, k;
	cin >> tc >> k;
	dp[0] = 1;
	for(int i = 1; i <= kMax; i++)
	{
		// Using a red flower
		dp[i] = dp[i-1];
		// Using a white flower
		if ( i-k >= 0 )
			dp[i] = ((long long)dp[i] + dp[i-k]) % inf;
	}
	sum[0] = 0;
	for(int i = 1; i <= kMax; i++)
		sum[i] = ((long long)sum[i-1] + dp[i]) % inf;
	while ( tc-- )
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int ans = ((long long)sum[b] - sum[a-1] + inf) % inf;
		printf("%d\n", ans);
	}

	return 0;
}