#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, left, right;
    string plate;

    cin >> n;
    while( n-- )
    {
        cin >> plate;
        left = (plate[0]-'A')*676 + (plate[1]-'A')*26 + (plate[2]-'A')*1;
        right = (plate[4]-'0')*1000 + (plate[5]-'0')*100 + (plate[6]-'0')*10 + (plate[7]-'0')*1;
        if( abs(left-right) > 100 )
        {
            cout << "not ";
        }
        cout << "nice" << endl;
    }

    return 0;
}
