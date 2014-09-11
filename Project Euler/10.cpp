#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;
vi is_prime, primes;

void sieve(int ubound)
{
    is_prime.assign(ubound, 1);
    is_prime[0] = is_prime[1] = 0;
    primes.clear();
    for(int i = 2; i*i < ubound; i++)
    {
        if ( is_prime[i] == false ) continue;
        for(int j = i*i; j < ubound; j += i) is_prime[j] = 0;
    }
    for(int i = 2; i < ubound; i++) if ( is_prime[i] )
        primes.push_back(i);
}

int main()
{
    unsigned long long sum = 0;
    
    sieve(2*1e6 + 1);
    for(int i = 0; i < (int)primes.size() && primes[i] <= 2*1e6; i++) sum += primes[i];
    cout << sum << endl;

    return 0;
}