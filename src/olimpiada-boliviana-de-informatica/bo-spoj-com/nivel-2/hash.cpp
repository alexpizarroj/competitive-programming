#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);

	string s;
	int pos, elem, sum;
	while ( getline(cin, s) )
	{
        pos = elem = sum = 0;
        for(size_t i = 0; i < s.size(); i++)
            if( s[i] == ' ' ) pos = 0, elem++;
            else 			  sum += (s[i]-'A') + pos + elem, pos++;
        printf("%d\n", sum);
	}
    return 0;
}
