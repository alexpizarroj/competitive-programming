#include <bits\stdc++.h>
using namespace std;

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	// Input processing
	char c;
	vector<int> vec;
	int running_size = 0;
	while ( scanf("%c", &c) != EOF )
	{
		if ( isalpha(c) )
			running_size += 1;
		else
		{
			if ( running_size > 0 )
				vec.push_back(running_size);
			running_size = 0;
		}
	}
	if ( running_size > 0 )
		vec.push_back(running_size);

	// Solving
	int n = vec.size();
	int ans = 0, running_max = 0;
	vector<int> dp(n);
	for(int i = 0; i < n; i++)
	{
		if ( i-2 >= 0 )
			running_max = max(running_max, dp[i-2]);
		dp[i] = running_max + vec[i];
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
	
	return 0;
}
