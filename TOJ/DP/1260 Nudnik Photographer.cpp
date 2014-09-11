#include <iostream>
using namespace std;

int main()
{
    int n, dp[56];
    
    dp[1] = dp[2] = 1, dp[3] = 2;
    for(int i = 4; i <= 55; i++) dp[i] = dp[i-1] + dp[i-3] + 1;
    while ( cin >> n ) cout << dp[n] << endl;
	
    return 0;
}
