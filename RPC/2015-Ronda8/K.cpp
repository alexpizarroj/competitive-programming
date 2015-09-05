#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n)
{
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  
  int lim = floor(sqrt(n)) + 1;
	for (int i = 3; i <= lim; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

bool rev(string &s)
{
	for (int i = 0; i < (int)s.size() / 2; ++i)
	{
		if (s[i] == '6') s[i] = '9';
		else if (s[i] == '9') s[i] = '6';
		else if (s[i] == '3' || s[i] == '4' || s[i] == '7') return false;
		
		swap(s[i], s[(int)s.size() - i - 1]);

		if (s[i] == '6') s[i] = '9';
		else if (s[i] == '9') s[i] = '6';
		else if (s[i] == '3' || s[i] == '4' || s[i] == '7') return false;
	}

	int n = (int)s.size();

	if (n % 2 != 0)
	{
		if (s[n/2] == '6') s[n/2] = '9';
		else if (s[n/2] == '9') s[n/2] = '6';
		else if (s[n/2] == '3' || s[n/2] == '4' || s[n/2] == '7') return false;
	}

	return true;
}


int main()
{
	string s;

	while(cin >> s)
	{
		long long a = stoll(s);	
		if (rev(s))
		{ 
			long long b = stoll(s);
			if (is_prime(a) && is_prime(b)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
		else cout << "no" << endl;
	}

  	return 0;
}



