#include <bits/stdc++.h>
using namespace std;

void setupFastIO()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main()
{
	setupFastIO();
	
	int riMostZero[105][105], riMostOne[105][105], mat[105][105], n;
	pair<int, int> dp[105];
	while ( cin >> n, n )
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> mat[i][j];
		
		for(int i = 0; i < n; i++)
		{
			int onePos = -1, zeroPos = -1;
			for(int j = n-1; j >= 0; j--)
			{
				if (mat[i][j] == 1 && (j+1 == n || mat[i][j+1] == 0))
					onePos = j;
				if (mat[i][j] == 0 && (j+1 == n || mat[i][j+1] == 1))
					zeroPos = j;
					
				riMostOne[i][j]  = onePos;
				riMostZero[i][j] = zeroPos;
			}
		}
		
		int ans = 0;
		memset(dp, 0, sizeof dp);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int side0 = dp[j].first, row0 = dp[j].second, side1 = 0, row1 = 0;
				
				// Is this a 1-starting row?
				if (mat[i][j] == 1)
				{
					int nOnes = riMostOne[i][j] - j + 1;
					if (j + nOnes < n)
					{
						int nZeros = riMostZero[i][j+nOnes] - (j+nOnes) + 1;
						if (j + nOnes + nZeros < n)
						{
							int nOtherOnes = riMostOne[i][j+nOnes+nZeros] - (j+nOnes+nZeros) + 1;
							if (nOnes <= nOtherOnes && nZeros%2 == 1)
							{
								// Row of a certain square found
								side1 = 2*nOnes + nZeros;
								row1 = (nZeros+1)/2;
								// Is this not a header row?
								if ( row1 > 1 )
								{
									// Then, we must be coming from a previous valid row
									if ( side0 == side1 && row0 < max(side1-row1+1, row1) )
										row1 = row0 + 1;
									else
										side1 = row1 = 0;
								}
							}
						}
					}
				}
				// Is this a 0-starting row?
				else if (side0 > 0 && row0 == (side0-1)/2)
				{
					int nZeros = riMostZero[i][j] - j + 1;
					if (side0 <= nZeros)
					{
						side1 = side0;
						row1 = (side1+1)/2;
					}
				}
				
				// Answer update
				if ( side0 > 0 && side0 == side1 && row0 == side0-1 && row1 == 1 )
					ans = max(ans, side1);
				// DP update
				dp[j].first  = side1;
				dp[j].second = row1;
			}
		}
		
		if (ans == 0)
			cout << "No solution\n";
		else
			cout << ans << "\n";
	}
	return 0;
}
