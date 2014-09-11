#include <iostream>
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
using namespace std;

int main()
{
    typedef long long ll;
    ll a, b, x, spent, mm;
    int n;
    
    while ( cin >> n >> a >> b, cin )
    {
        fup(i,0,n)
        {
            cin >> x;
            
            mm = (x*a)/b;
            if ( (mm*b)%a == 0 )    spent = (mm*b)/a;
            else                    spent = ((mm*b)/a)+1;
            
            cout << (i > 0 ? " " : "") << (x - spent);
        }
        cout << endl;
    }
    
    return 0;
}
