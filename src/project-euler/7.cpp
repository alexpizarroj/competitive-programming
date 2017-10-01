#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi prime, lst;
void sieve(int ubound)
{
    prime.assign(ubound, 1);
    prime[0] = prime[1] = 0;
    for(int i = 2; i*i < ubound; i++)
    {
        if ( !prime[i] ) continue;
        for(int j = i*i; j < ubound; j += i)
            prime[j] = 0;
    }
    lst.clear();
    for(int i = 2; i < ubound; i++) if ( prime[i] )
        lst.push_back(i);
}

int main()
{
    sieve(150000);
    cout << lst[10000] << endl;

    return 0;
}