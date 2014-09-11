#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int r;
    while ( b > 0 ) r = a%b, a = b, b = r;
    return a;
}

long long lcm(long long a, long long b)
{
    return a / gcd(a,b) * b;
}

int main()
{
    long long ans = 1;
    for(int i = 1; i <= 20; i++) ans = lcm(ans,i);
    cout << ans << endl;

    return 0;
}