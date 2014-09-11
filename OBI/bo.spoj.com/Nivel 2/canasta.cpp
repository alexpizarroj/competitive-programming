#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, best, caseNo = 1;
    vector<int> vec;
	char buffer[20];

	while ( gets(buffer) != NULL )
	{
		scanf("%d", &n);
		vec.resize(n);
		for(int i = 0; i < n; i++) scanf("%d", &vec[i]);
		getchar();

		sort(vec.begin(), vec.end());
		best = vec[0] * n;
		for(int i = 1; i < n; i++) best = max(best, vec[i] * (n-i));
		printf("Salida para el ejemplo %d\n%d\n", caseNo++, best);
	}

    return 0;
}
