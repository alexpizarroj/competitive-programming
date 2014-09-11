#include <iostream>
using namespace std;

char current[30];
void rec(int pos, int opened, int rem)
{
	if ( rem > 0 )
	{
		current[pos] = '(';
		rec(pos+1, opened+1, rem-1);
	}
	if ( opened > 0 )
	{
		current[pos] = ')';
		rec(pos+1, opened-1, rem);
	}
	if ( opened == 0 && rem == 0 )
		printf("%s\n", current);
}

int main()
{
    int n;
	while ( cin >> n )
	{
		current[2*n] = 0;
		rec(0, 0, n);
	}
    return 0;
}
