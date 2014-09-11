#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	double v;
	for(int i = 0; i < 100; ++i)
	{
	    cin >> v;
	    if ( v <= 10 ) cout << "A[" << i << "] = " << v << endl;
	}

    return 0;
}
