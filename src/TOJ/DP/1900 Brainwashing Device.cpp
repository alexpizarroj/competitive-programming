#include <bits\stdc++.h>
using namespace std;

int N, K;
int dp[505][505], dp_choice[505][505];
int people[505][505], people_dp[505][505];

int submatrix_sum(int i0, int j0, int i1, int j1)
{
	int ans = people_dp[i1][j1];
	if ( i0 > 0 )
		ans -= people_dp[i0-1][j1];
	if ( j0 > 0 )
		ans -= people_dp[i1][j0-1];
	if ( i0 > 0 && j0 > 0 )
		ans += people_dp[i0-1][j0-1];
	return ans;
}

int f(int nStations, int nDevices)
{
	if (nStations == 1 || nDevices == 0)
		return 0;

	int &ans = dp[nStations][nDevices];
	if (ans == -1)
	{
		// Default state value
		ans = 0;
		// DP state solving
		const int starting_station = N - nStations;
		for(int cut = 0; cut < nStations-1; ++cut)
		{
			const int ending_station = starting_station + cut;

			int cand_p1 = submatrix_sum(
				starting_station, 	ending_station+1,
				ending_station, 	N-1
			);
			int cand_p2 = f(nStations-cut-1, nDevices-1);
			int cand = cand_p1 + cand_p2;

			if (cand > ans || dp_choice[nStations][nDevices] == -1)
			{
				dp_choice[nStations][nDevices] = cut;
				ans = cand;
			}
		}
	}
	return ans;
}

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	while ( cin >> N >> K )
	{
		// People's matrix
		memset(people, 0, sizeof people);
		for(int i = 0; i < N-1; i++)
			for(int j = i+1; j < N; ++j)
				cin >> people[i][j];

		// Submatrix sums DP
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
			{
				people_dp[i][j] = people[i][j];
				if ( i > 0 )
					people_dp[i][j] += people_dp[i-1][j];
				if ( j > 0 )
					people_dp[i][j] += people_dp[i][j-1];
				if ( i > 0 && j > 0 )
					people_dp[i][j] -= people_dp[i-1][j-1];
			}

		memset(dp, -1, sizeof dp);
		memset(dp_choice, -1, sizeof dp_choice);
		cout << f(N, K) << "\n";

		int n = N, k = K;
		while ( dp_choice[n][k] != -1 )
		{
			int cut = dp_choice[n][k];
			cout << (N - n + cut + 1) << (k > 1 ? " " : "");
			n -= 1 + cut;
			k -= 1;
		}
		cout << "\n";
	}
	return 0;
}
