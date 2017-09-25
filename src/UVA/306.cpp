#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <string.h>
#define BUFFERLEN 300
#define ULL unsigned long long

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char s[BUFFERLEN], *msg, *msg2;
	int n, *pi, **cycles, i, j, c, *cnt, len;
	ULL k;

	memset(s, 0, BUFFERLEN);
	while ( true ) {
	    // Entrada
	    scanf("%d\n", &n);
	    if(!n) break;
	    pi = new int[n];
        for( i = 0; i != n; i++ ) {  scanf("%d", &pi[i]); pi[i]--; }
        getchar();
        // Contar ciclos de permutacion
        cycles = new int*[n];
        memset(cycles, NULL, sizeof(int*)*n);
        for(i = 0; i != n; i++) {
            if ( cycles[i] != NULL ) continue;
            j = pi[i]; cnt = new int(1);
            cycles[i] = cnt;
            while ( i != j ) {
                cycles[j] = cnt;
                (*cnt)++; j = pi[j];
            }
        }
        // Resolucion
        while ( true ) {
            gets(s);
            sscanf(s, "%llu", &k);
            if(!k) break;
            // Obtener mensaje y normalizar tamaño
            i = 0; while ( isdigit(s[i]) ) i++;
            msg = &s[i+1]; len = strlen(msg);
            if(len != n) {
                for(i = len; i != n; i++) msg[i] = ' ';
                msg[n] = 0;
            }
            // Encriptar
            msg2 = new char[n+1]; msg2[n] = 0;
            for(i = 0; i != n; i++) {
                c = k % (*cycles[i]); j = i;
                while (c--) j = pi[j];
                msg2[j] = msg[i];
            }
            // Salida
            printf("%s\n", msg2);
        }
        printf("\n");
	}

    return 0;
}


