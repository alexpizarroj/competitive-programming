#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int f[100005];

int main()
{
	const int START = 0, END = 1;
	typedef pair<int,int> ii;
	typedef pair<int,ii> iii;
	vector<iii> events;
	int n, s, e, ans;
	
	while ( ~scanf("%d", &n) )
	{
		events.clear();
		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d", &s, &e);
			events.push_back( iii(s, ii(START,i)) );
			events.push_back( iii(e, ii(END,i) ) );
		}
		ans = -1;
		sort(events.begin(), events.end(), greater<iii>());
		for(int i = 0; i < (int)events.size(); i++)
		{
			int kind = events[i].second.first;
			int eventId = events[i].second.second;
			if ( kind == END ) f[eventId] = ans + 1;
			else 			   ans = max(ans, f[eventId]);
		}
		cout << ans+1 << endl;
	}
	
	return 0;
}