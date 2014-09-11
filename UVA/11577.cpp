#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t, i, len, freq[129], maxFreq;
    char s[201];

    scanf("%d", &t); getchar();
    while (t--) {
        // Entrada
        gets(s);
        len = strlen(s);
        // Resolucion
        memset(freq, 0, sizeof(int)*129);
        for(i = 0; i != len; i++) {
            s[i] = tolower(s[i]);
            freq[ (int)s[i] ]++;
        }
        maxFreq = 0; len = 'z'+1;
        for(i = 'a'; i != len; i++)
            maxFreq = max(maxFreq, freq[i]);
        // Salida
        for(i = 'a'; i != len; i++)
            if( freq[i]==maxFreq )
                printf("%c", i);
        printf("\n");
    }

    return 0;
}
