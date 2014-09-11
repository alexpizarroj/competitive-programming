#include <cstdio>

int main()
{
    int n;
	while ( scanf("%d", &n), n > 0 )
	{
		bool space = false;
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if ( x > 0 )
			{
				if ( space ) printf(" ");
				printf("%d", x);
				space = true;
			}
		}
		if ( !space )
			printf("0");
		printf("\n");
	}
    return 0;
}
