#include <bits\stdc++.h>
using namespace std;

const int inf = int(1e9) + 7;
vector< vector<int> > best_len, ways;
string A, B;
int L1, L2;

int getBestLen(int p1, int p2)
{
	if (p1 < 0 || p2 < 0)
		return inf;
	return best_len[p1][p2];
}

void ensure_solved(int p1, int p2)
{
	// Is this a valid state?
	if (p1 < 0 || p2 < 0)
		return;

	// Is this state already resolved?
	if (best_len[p1][p2] != -1) // Same as checking if ways[p1][p2] > 0
		return;

	// Solve required sub-states
	ensure_solved(p1-1, p2-1);
	ensure_solved(p1-1, p2);
	ensure_solved(p1, p2-1);

	// Current state solution
	bool equalEndings = (p1 > 0 && p2 > 0 && A[p1-1] == B[p2-1]);
	if (equalEndings)
	{
		best_len[p1][p2] = getBestLen(p1-1, p2-1) + 1;
		ways[p1][p2] += ways[p1-1][p2-1];
	}
	else
	{
		int left = getBestLen(p1-1, p2) + 1;
		int top = getBestLen(p1, p2-1) + 1;
		best_len[p1][p2] = min(left, top);
		
		if (best_len[p1][p2] == left)
			ways[p1][p2] += ways[p1-1][p2];
		if (best_len[p1][p2] == top)
			ways[p1][p2] += ways[p1][p2-1];
		if (ways[p1][p2] >= inf)
			ways[p1][p2] -= inf;
	}
}

int solve()
{
	L1 = A.size();
	L2 = B.size();
	best_len.assign(L1+1, vector<int>(L2+1, -1));
	ways.assign(L1+1, vector<int>(L2+1, 0));
	best_len[0][0] = 0;
	ways[0][0] = 1;
	ensure_solved(L1, L2);
	return ways[L1][L2];
}

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	while (cin >> A >> B)
		cout << solve() << '\n';	
	return 0;
}
