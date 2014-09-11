#include <algorithm>
#include <cstdio>
using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    #endif

	int t, M, N, val;
	char P;

	scanf("%d", &t); getchar();
	while (t--)
	{
		scanf("%c %d %d", &P, &M, &N); getchar();
		switch (P) {
            case 'Q':
            case 'r':
                val = min(M, N);
                break;
            case 'k':
                val = int(((float)M*N)/2+0.5);
                break;
            case 'K':
                val = ((M+1)/2) * ((N+1)/2);
                break;
		}
		printf("%d\n", val);
	}
}
