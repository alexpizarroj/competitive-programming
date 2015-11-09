#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, c;
	bool valid = true;

	cin >> n;

	cin >> c;

	for (int i = 1; i < n; ++i)
	{
		cin >> x;
		if (c > x) valid = false;

		c = x;
	}	


	if (valid) cout << "yes" << endl;
	else cout << "no" << endl;

  	return 0;
}



