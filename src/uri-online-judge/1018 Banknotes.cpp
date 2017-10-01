#include <iostream>
using namespace std;

int main()
{
    int value;
    int banknote[] = {100, 50, 20, 10, 5, 2, 1};
    int len = sizeof(banknote)/sizeof(banknote[0]);
    
    cin >> value;
    cout << value << endl;
    for(int i = 0; i < len; ++i)
    {
        int note = banknote[i];
        cout << (value/note) << " nota(s) de R$ " << note << ",00" << endl;
        value = value%note;
    }
    
    return 0;
}