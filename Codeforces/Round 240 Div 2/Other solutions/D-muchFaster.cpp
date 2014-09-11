#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL mod=1000000007;
const int maxn=2010;
LL dp[2][maxn];
int n,k;
int main()
{
	cin>>n>>k;
	int flag=0;
	for(int i=1;i<=n;i++) dp[flag][i]=1;
	for(int i=1;i<k;i++)
	{
		memset(dp[flag^1],0,sizeof(dp[flag^1]));
		for(int j=1;j<=n;j++)
			for(int p=1;p*j<=n;p++)
				dp[flag^1][p*j]=(dp[flag^1][p*j]+dp[flag][j])%mod;
		flag^=1;
	}
	LL ans=0;
	for(int i=1;i<=n;i++) ans=(ans+dp[flag][i])%mod;
	cout<<ans<<"\n";
	return 0;
}