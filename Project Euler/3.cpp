#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 775200;
bool prime[MAX];
vector<int> lst;

void sieve(int ubound)
{
    lst.clear();
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = 0;
    for(int i = 2; i*i < ubound; i++)
    {
        if ( !prime[i] ) continue;
        for(int j = i*i; j < ubound; j += i)
            prime[j] = false;
    }
    for(int i = 2; i < ubound; i++)
        if ( prime[i] ) lst.push_back(i);
}

int main()
{
    long long n = 600851475143L;
    int ans = 1;
    
    sieve(MAX);
    for(int i = lst.size()-1; i >= 0; i--)
    {
        if ( n%lst[i] == 0 ) { ans = lst[i]; break; } 
    }
    cout << ans << endl;
	
    return 0;
}
