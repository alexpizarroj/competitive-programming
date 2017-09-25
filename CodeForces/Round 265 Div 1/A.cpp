#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const char INV_CHAR = '?';
char getNext(int p, int pos, const string &s)
{
	char prev1 = (pos-1 >= 0 ? s[pos-1] : INV_CHAR);
	char prev2 = (pos-2 >= 0 ? s[pos-2] : INV_CHAR);
	for(char c = s[pos]+1; c < int('a')+p; ++c)
		if ( c != prev1 && c != prev2 )
			return c;
	return INV_CHAR;
}

int main()
{
	int n, p;
	while ( cin >> n >> p )
	{
		string s;
		cin >> s;
		if ( p == 1 )
		{
			puts("NO");
			continue;
		}
		else if ( p == 2 )
		{
			if ( n == 1 )
				puts(s == "a"  ? "b"  : "NO");
			else
				puts(s == "ab" ? "ba" : "NO");
			continue;
		}
		bool found = false;
		for(int i = (int)s.size()-1; i >= 0; --i)
		{
			char next = getNext(p, i, s);
			if ( next != INV_CHAR )
			{
				s[i] = next;
				for(i = i+1; i < (int)s.size(); i++)
				{
					s[i] = int('a') - 1;
					s[i] = getNext(p, i, s);
				}
				found = true;
				break;
			}
		}
		cout << (found ? s : "NO") << "\n";
	}
    return 0;
}
