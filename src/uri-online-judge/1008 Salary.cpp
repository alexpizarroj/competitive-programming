#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int id, hours;
	float salary;
	
	cin >> id >> hours >> salary;
	cout.precision(2);
	cout << "NUMBER = " << id << endl;
	cout << "SALARY = U$ " <<
		fixed << setprecision(2) << (salary * hours) << endl;
	
	return 0;
}