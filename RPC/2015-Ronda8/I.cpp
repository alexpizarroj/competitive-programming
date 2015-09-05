#include <bits/stdc++.h>
using namespace std;

int main()
{
	int w, s, x, y;

	while(cin >> w >> s >> x >> y)
	{
		vector<vector<int>> v(w, vector<int>(x));
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < x; ++j)
			{
				cin >> v[i][j];
			}
		}
		vector<int> p(x, -1);
		int a;
		for (int i = 0; i < s; ++i)
		{
			for (int j = 0; j < x; ++j)
			{
				cin >> a;
				p[j] = max(a, p[j]);
			}
		}
		for (int i = 0; i < w; ++i)
		{
			for (int j = 0; j < x; ++j)
			{
				if (j > 0) cout << " ";
				if(v[i][j] + p[j] > y) 	cout << y - p[j];
				else 					cout << v[i][j];

			}

			cout << endl;
		}
	}

  	return 0;
}
