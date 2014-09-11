#include <iostream>
using namespace std;

int main()
{
    long long n;
    long long h, m, s;
    cin >> n;
    
    h = n/3600, n = n % 3600;
    m = n/60, n = n % 60;
    s = n;
    cout << h << ":" << m << ":" << s << endl;
    
    return 0;
}