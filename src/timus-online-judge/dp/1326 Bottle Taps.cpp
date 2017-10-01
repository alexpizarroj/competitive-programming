#include <bits\stdc++.h>
using namespace std;

int lsbPos[1<<20];

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	// Precalculations
	for(int i = 0; i < 20; i++)
		lsbPos[1<<i] = i;

	int n;
	while (cin >> n)
	{
		// Store offers processing
		vector<int> storePrice(n);
		for(int i = 0; i < n; i++)
			cin >> storePrice[i];

		// Online offers bitmask generation
		int nOffers;
		cin >> nOffers;
		vector< pair<int, int> > onlineOffers;
		for(int i = 0; i < nOffers; i++)
		{
			int price, nTaps;
			cin >> price >> nTaps;
			int offerMask = 0;
			for(int j = 0; j < nTaps; j++)
			{
				int tap;
				cin >> tap;
				offerMask |= (1 << (tap-1));
			}
			onlineOffers.push_back(make_pair(price, offerMask));
		}

		// Wanted taps bitmask
		int wantedMask = 0;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int tap;
			cin >> tap;
			wantedMask |= (1 << (tap-1));
		}

		// Solution
		vector<int> minCost(wantedMask+1);
		minCost[0] = 0;
		for(int mask = 1; mask <= wantedMask; mask++)
		{
			int lsb = mask & (-mask);
			int pos = lsbPos[lsb];
			minCost[mask] = storePrice[pos] + minCost[mask & (~lsb)];
			for(int i = 0; i < (int)onlineOffers.size(); i++)
			{
				int cost = onlineOffers[i].first;
				int offer = onlineOffers[i].second;
				if (offer & lsb)
				{
					minCost[mask] = min(
						minCost[mask],
						cost + minCost[mask & (~offer)]
					);
				}
			}
		}
		cout << minCost[wantedMask] << "\n";
	}
	return 0;
}
