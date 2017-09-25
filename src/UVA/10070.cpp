#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool multOf4(const string& n)
{
    int a, b, newLastDigit;

    a = ( n.size() >= 2 ? n[n.size()-2]-'0' : 0);
    b = n[n.size()-1]-'0';
    newLastDigit = (b/2) + (a%2==1 ? 5: 0);

    return (b%2==0) && ( newLastDigit%2 == 0 );
}

bool multOf100(const string& n)
{
    return ( n[ n.size()-2 ] == '0' && n[ n.size()-1 ] == '0' );
}

bool multOf400(const string& n)
{
    bool ret = false;

    if( n.size() >= 3 && multOf100(n) )
    {
        int a, b, newLastDigit;

        a = ( n.size() >= 4 ? n[n.size()-4]-'0' : 0);
        b = n[n.size()-3]-'0';
        newLastDigit = (b/2) + (a%2==1 ? 5: 0);

        ret = (b%2==0) && ( newLastDigit%2 == 0 );
    }

    return ret;
}

bool multOf3(const string& n)
{
    int sum = 0;

    for(size_t i = 0; i < n.size(); i++)
        sum = (sum +  (n[i]-'0')%3 )%3;

    return (sum == 0);
}

bool multOf5(const string& n)
{
    return ( n[n.size()-1] == '0' || n[n.size()-1] == '5' );
}

bool multOf11(const string &n)
{
    int sum = 0;
    bool add = true;

    for(size_t i = 0; i < n.size(); i++)
    {
        if( add )   sum = (sum + (n[i]-'0')%11)%11;
        else        sum = (sum - (n[i]-'0')%11)%11;
        add = !add;
    }
    sum = abs(sum);

    return (sum == 0);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	string n;
	bool first = true;
	bool leap, hulu, bulu, special;

	while ( cin >> n )
	{
	    if( !first ) puts("");

	    leap = multOf4(n) && ( !multOf100(n) || multOf400(n) );
	    hulu = multOf3(n) && multOf5(n);
	    bulu = leap && multOf5(n) && multOf11(n);
	    special = leap || hulu || bulu;

	    if( leap ) puts("This is leap year.");
	    if( hulu ) puts("This is huluculu festival year.");
	    if( bulu ) puts("This is bulukulu festival year.");
	    if( !special ) puts("This is an ordinary year.");

        first = false;
	}

    return 0;
}
