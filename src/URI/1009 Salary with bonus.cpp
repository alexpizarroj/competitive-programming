#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string name;
    double salary, sold;
    
    cin >> name >> salary >> sold;
    cout << "TOTAL = R$ " << fixed << setprecision(2) <<
        (salary + sold*0.15) << endl;
    
    return 0;
}