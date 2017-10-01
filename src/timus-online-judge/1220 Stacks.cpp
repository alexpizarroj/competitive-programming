#include <stdio.h>
#include <stdlib.h>

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    // We'll use 18 bits for a back-pointer and 30 for the actual value (48 bits, 6 bytes in total).
    unsigned short *a = (unsigned short*)malloc(sizeof(short)*100000);
    unsigned int *b = (unsigned int*)malloc(sizeof(int)*100000);

    // Local variables
    int top[1001], N = 0;
	int n, nStack, v, idx, bp;
	char ins[5];

    // Processing
	scanf("%d", &n);
	while (n--)
	{
        scanf("%s", ins);
        if( ins[1] == 'U' )
        {
            scanf("%d %d", &nStack, &v);
            // PUSH
            bp = top[nStack];
            a[N] = (bp>>2);
            b[N] = (v & ((1<<30)-1)) | (bp<<30);
            top[nStack] = N++;
        }
        else
        {
            scanf("%d", &nStack);
            // POP
            idx = top[nStack];
            top[nStack] = ((a[idx]<<2) + (b[idx]>>30));
            printf("%d\n", (b[idx] & ((1<<30)-1)) );
        }
	}

	// Memory freeing
	free(a); free(b);

    return 0;
}
