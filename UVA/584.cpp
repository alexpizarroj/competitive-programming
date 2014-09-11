#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;


static char s[50];
static int len, pos;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int score, rolls, v[50], pins, lastPins, i, j, frame;
    char c;

    while ( true ) {
        // Entrada
        gets(s);
        if( strcmp(s, "Game Over")==0 ) break;
        len = strlen(s);
        // Preparar informacion
        rolls = (len+1)/2;
        score = 0;
        lastPins = 0;
        for(i = 0, pos = 0; i != rolls; i++, pos += 2) {
            // Datos
            c = s[pos];
            if(c == 'X')
                pins = 10;
            else if (c == '/')
                pins = 10-lastPins;
            else
                pins = c-'0';
            lastPins = pins;
            v[i] = pins;
        }
        // Resolucion
        for(i = 0, j = 0, pos = 0, frame = 1; i != rolls && frame != 11; i++, pos += 2) {
            c = s[pos]; pins = v[i];
            score += pins; j++;
            if(c == '/') {
                score += v[i+1];
                frame++; j = 0;
            } else if(c == 'X') {
                score += v[i+1] + v[i+2];
                frame++; j = 0;
            }
            if(j==2) { frame++; j = 0; }
        }
        // Salida
        printf("%d\n", score);
    }

    return 0;
}
