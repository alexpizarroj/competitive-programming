#include <bits\stdc++.h>
using namespace std;

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	const int inf = int(1e9) + 7;
	int n, t[2], f[50005][2];
	while (cin >> n >> t[0] >> t[1])
	{
		f[0][0] = f[0][1] = 1;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < 2; j++)
			{
				f[i][j] = 0;
				for(int k = 1; k <= min(i, t[j]); k++)
					f[i][j] = (f[i][j] + f[i-k][1-j]) % inf;
			}

		int ans = (f[n][0] + f[n][1]) % inf;
		cout << ans << "\n";
	}
	return 0;
}
