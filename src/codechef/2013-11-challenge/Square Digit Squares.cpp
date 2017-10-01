#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_valid[10] = {1,1,0,0,1,0,0,0,0,1};
typedef long long Number;

bool has_valid_digits(Number n)
{
    while ( n > 0 )
    {
        if ( !is_valid[(n%10)] ) return false;
        n /= 10;
    }
    return true;
}

int main()
{
    int tc;
    vector<Number> v;
    Number a, b, k;
    
    for(int i = 1; i <= 100000; ++i)
    {
        k = Number(i)*i;
        if ( has_valid_digits(k) ) v.push_back(k);
    }
    cin >> tc;
    while ( tc-- )
    {
        cin >> a >> b;
        cout << distance( lower_bound(v.begin(), v.end(), a),
            upper_bound(v.begin(), v.end(), b) ) << endl;
    }
    
    return 0;
}
