#include <stdio.h>

using namespace std;


struct SIGN {
    SIGN(const char* pname, int pm1, int pd1, int pm2, int pd2) : name((char*)pname), m1(pm1), d1(pd1), m2(pm2), d2(pd2) {}
    char* name;
    int m1, d1, m2, d2;
};

static int mdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static SIGN *signs[12];

inline bool leap(int y) { return (y%4==0 && (y % 100 != 0 || y % 400 == 0)); }

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char input[10];
    int c = 1, C;
    int m, d, y, daysLeft, i;

    // Establecer signos del zodiaco
    signs[0] = new SIGN("aquarius", 1, 21, 2, 19);
    signs[1] = new SIGN("pisces", 2, 20, 3, 20);
    signs[2] = new SIGN("aries", 3, 21, 4, 20);
    signs[3] = new SIGN("taurus", 4, 21, 5, 21);
    signs[4] = new SIGN("gemini", 5, 22, 6, 21);
    signs[5] = new SIGN("cancer", 6, 22, 7, 22);
    signs[6] = new SIGN("leo", 7, 23, 8, 21);
    signs[7] = new SIGN("virgo", 8, 22, 9, 23);
    signs[8] = new SIGN("libra", 9, 24, 10, 23);
    signs[9] = new SIGN("scorpio", 10, 24, 11, 22);
    signs[10] = new SIGN("sagittarius", 11, 23, 12, 22);
    signs[11] = new SIGN("capricorn", 12, 23, 1, 20);

    // Entrada
    scanf("%d", &C); getchar();
    while (C--) {
        fgets(input, 10, stdin);
        sscanf(input, "%2d%2d%4d", &m, &d, &y);
        // Calcular fecha de nacimiento
        mdays[2] = ( leap(y) ? 29 : 28 );
        daysLeft = 280;
        while ( daysLeft > 0 ) {
            i = mdays[m]-d+1;
            if(daysLeft < i) {
                d += daysLeft;
                daysLeft = 0;
            } else {
                daysLeft -= i;
                d = 1; m++;
                if(m > 12) {
                    y++;
                    m = 1;
                    mdays[2] = ( leap(y) ? 29 : 28 );
                }
            }
        }
        // Calcular signo
        for(i = 0; i != 12; i++)
            if( (m == signs[i]->m1 && d >= signs[i]->d1) || (m == signs[i]->m2 && d <= signs[i]->d2) )
                break;
        // Salida
        printf("%d %.2d/%.2d/%.4d %s\n", c++, m, d, y, signs[i]->name);
    }

    return 0;

};
