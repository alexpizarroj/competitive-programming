#include <stdio.h>
#include <map>
#include <math.h>
#define ISMAP map<int, short>

using namespace std;

static ISMAP mp;

void fillmp(int m) {
    int i, lim, m_original=m;
    mp.clear();
    //
    while(m%2==0) {
        mp[2]++;
        m /= 2;
    }
    lim = sqrt(m)+1; i = 3;
    while ( i <= lim ) {
        if( m%i==0 ) {
            mp[i]++;
            m /= i;
            lim = sqrt(m)+1;
        } else i+=2;
    }
    //
    if(m != m_original && m != 1) mp[m]++;
}

inline int getPrimeExp(int factorialNumber, int prime) {
    int res = 0; long long power;
    for (power = prime; power <= factorialNumber ; power *= prime) res += trunc(factorialNumber/power);
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, m, base, exp, exp2;
    ISMAP::iterator it;
    bool divides;


    while ( scanf("%d %d", &n, &m) != EOF ) {
        // Resolucion
        divides = true;
        if ( !(m == 1 || m == n || m <= n || m == 0) ) {
            fillmp(m);
            if(mp.size() == 0) divides = false;
            else {
                for(it = mp.begin(); it != mp.end(); it++) {
                    base = (*it).first;
                    exp = (*it).second; // exponente en el divisor
                    exp2 = getPrimeExp(n, base); // exponente en el factorial
                    if(exp > exp2) {
                        divides = false;
                        break;
                    }
                }
            }
        }
        if(m == 0) divides = false;
        // Salida
        printf((divides ? "%d divides %d!\n" : "%d does not divide %d!\n"), m, n);
    }

    return 0;
}
