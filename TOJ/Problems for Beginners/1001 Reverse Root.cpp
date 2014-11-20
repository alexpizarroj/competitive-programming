#include <bits\stdc++.h>
using namespace std;

int main()
{   
	vector<double> vec;
	long long a;

	while (scanf("%lld", &a) != EOF)
		vec.push_back(sqrt((double)a));

	for(int i = (int)vec.size() - 1; i >= 0; i--)
		printf("%.4lf\n", vec[i]);
	
	return 0;
}
