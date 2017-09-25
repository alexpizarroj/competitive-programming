#include <iostream>
#include <vector>
using namespace std;

int dp[60005];

int main()
{
    vector<int> coins;
    int n;
    
    dp[0] = 0;
    for(int i = 1; i*i <= 60000; i++) coins.push_back(i*i);
    for(int i = 1; i <= 60000; i++)
    {
        dp[i] = 1e9+7;
        for(int j = 0; j < (int)coins.size() && coins[j] <= i; j++)
        {
            dp[i] = min(dp[i], dp[i-coins[j]]+1);
        }
    }
    while ( cin >> n, cin ) cout << dp[n] << endl;
	
    return 0;
}
