#include <iostream>
using namespace std;

int main()
{
    const int lim = 4e6;
    int a = 1, b = 2, c;
    long long sum = 0;
    
    while ( b <= lim )
    {
        if ( (b&1) == 0 ) sum += b;
        c = a + b;
        a = b, b = c;
    }
    cout << sum << endl;
	
    return 0;
}
