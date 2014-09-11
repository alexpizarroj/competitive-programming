#include <stdio.h>
#include <memory.h>
#include <string.h>
#define BESTSTRLEN 1000001

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int ls, lt, i, j;
	char s[BESTSTRLEN], t[BESTSTRLEN];
	memset(s, 0, BESTSTRLEN);
	memset(t, 0, BESTSTRLEN);

	while ( scanf("%s %s", s, t) != EOF ) {
        ls = strlen(s); lt = strlen(t);
        if( ls > lt ) printf("No\n");
        else if (ls == lt) printf( (strcmp(s, t) == 0 ? "Yes\n" : "No\n") );
        else {
            for(i = 0, j = 0; i != ls; i++) {
                while( s[i] != t[j] && j != lt ) j++;
                if(j == lt) break; else j++;
            }
            if(i == ls) printf("Yes\n"); else printf("No\n");
        }
	}

    return 0;
}
