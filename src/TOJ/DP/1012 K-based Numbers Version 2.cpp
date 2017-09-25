#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

string add(const string &a, const string &b) 
{ 
	int LA = a.size(), LB = b.size(), L = max(LA, LB), carry = 0;
    
    string x = string(L, '0'); 
    
    while(L--)
    {
    	LA--; LB--;
    	
        if(LA >= 0) carry += a[LA] - '0'; 
        if(LB >= 0) carry += b[LB] - '0'; 
        
        if(carry < 10) x[L] = '0' + carry, carry = 0;
        else x[L] = '0' + carry - 10, carry = 1;
    }
    
    if(carry) x = '1' + x; 
    return x;
} 

string multiply(string a, string b)
{
	if(a=="0" || b=="0") return "0";
	else if(a.size()==1)
	{
		int m = a[0] - '0';
		
		string ans = string(b.size(), '0');
		
		int lleva = 0;
		
		for(int i=b.size()-1; i>=0; i--)
		{
			int d = (b[i] - '0') * m + lleva;
			lleva = d/10;
			ans[i] += d%10;
		}
		if(lleva) ans = (char)(lleva + '0') + ans;
		return ans;
	}
	else if(b.size()==1) return multiply(b, a);
	else
	{
		string ans = "0";
		string ceros = "";
		for(int i=a.size()-1; i>=0; i--)
		{
			string s = multiply(string(1, a[i]), b) + ceros;
			ceros += "0";
			ans = add(ans, s);
		}
		return ans;
	}
}

string toString(int n)
{
	char buffer[3];
	sprintf(buffer, "%d", n);
	return string(buffer);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	vector<string> memo;
	
	while ( scanf("%d %d", &n, &k) != EOF )
	{
	    string k_minus_1 = toString(k-1);
		memo.clear();
		
		memo.push_back( "0" );
		memo.push_back( k_minus_1 );
		memo.push_back( toString(k * (k - 1)) );
		
		for(int i = 3; i <= n; i++)
		{
			memo.push_back(
				multiply(k_minus_1, add(memo[i - 1], memo[i - 2]))
			);
		}
		
		printf("%s\n", memo[n].c_str());
	}

    return 0;
}
