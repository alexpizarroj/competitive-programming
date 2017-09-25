#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while ( getline(cin,s), cin )
        cout << s << endl;

    return 0;
}
