#include <cstdio>

const int cstMax = 100005;
const int cstEmptyStack = -1;
char vstack[cstMax], number[cstMax];

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, d, top;

	while ( scanf("%d %d", &n, &d), (n || d))
    {
        top = cstEmptyStack;
        scanf("%s", number);
        for(int i = 0; i < n; i++)
        {
            char current = number[i];
            while ( d > 0 && top != cstEmptyStack && vstack[top] < current )
                --top, --d;
            vstack[++top] = current;
        }
        top -= d;
        vstack[top+1] = 0;
        printf("%s\n", vstack);
    }

    return 0;
}
