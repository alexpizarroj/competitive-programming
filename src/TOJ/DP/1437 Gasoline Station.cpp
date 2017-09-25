#include <bits\stdc++.h>
using namespace std;

struct State
{
	unsigned char used[3];

	State() 
	{
		memset(used, 0, sizeof used);
	}

	State(int cap1, int cap2, int cap3)
	{
		used[0] = (unsigned char)cap1;
		used[1] = (unsigned char)cap2;
		used[2] = (unsigned char)cap3;
	}
};

bool visited[256][256][256];

int solve(const int cap[])
{
	int max_volume = cap[0] + cap[1] + cap[2];
	vector<int> reached(max_volume+1, 0);

	queue<State> q;
	q.push(State(0, 0, 0));
	memset(visited, 0, sizeof visited);
	visited[0][0][0] = true;

	while (!q.empty())
	{
		State u = q.front();
		q.pop();
		// Update reached states
		for(int i = 1; i < (1<<3); i++)
		{
			int volume = 0;
			for(int j = 0; j < 3; j++)
				if ((i >> j) & 1)
					volume += (int)u.used[j];
			reached[volume] = 1;
		}
		
		// Fill the cans
		for(int i = 0; i < 3; i++)
		{
			State v(u);
			v.used[i] = (unsigned char)cap[i];

			bool &been_here = visited[(int)v.used[0]][(int)v.used[1]][(int)v.used[2]];
			if (been_here == false)
			{
				been_here = true;
				q.push(v);
			}
		}
		// Move from one can to another
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
			{
				if (i == j)
					continue;

				State v(u);
				int var = min((int)v.used[i], cap[j] - (int)v.used[j]);
				v.used[i] -= var;
				v.used[j] += var;

				bool &been_here = visited[(int)v.used[0]][(int)v.used[1]][(int)v.used[2]];
				if (been_here == false)
				{
					been_here = true;
					q.push(v);
				}
			}
	}

	int ans = accumulate(reached.begin(), reached.end(), 0) - 1;
	return ans;
}

int main()
{   
	// Fast IO
	ios_base::sync_with_stdio(0); cin.tie(0);

	int cap[3];
	while (cin >> cap[0] >> cap[1] >> cap[2])
		cout << solve(cap) << '\n';
	return 0;
}
