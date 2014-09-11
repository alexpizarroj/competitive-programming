#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <list>
#include <sstream>
#include <string>
#include <cstring>

#include <memory.h>
#include <algorithm>
#include <cmath>

#define FORX(i,start,end) for(i=start;i<end;i++)
#define FORY(i,start,end) for(i=start;i<=end;i++)

using namespace std;

map<char,char> mirror;
string pairs = "AAE3HHIIJLLJMMOOS2TTUUVVWWXXYYZ5112S3E5Z88";


bool isPalindrome(string s)
{
    int len = s.length();
    int k = len/2, i, j;
    for(i = 0, j = len-1; i < k; i++, j--)
    {
        if( s[i] != s[j] )
            return false;
    }
    return true;
}

bool isMirrored(string s)
{
    int i, len = s.length();
    string t = s;

    FORX(i,0,len)
    {
        if( mirror.find(s[i]) == mirror.end() )
            return false;
        else
            t[i] = mirror[s[i]];
    }


    t = string( t.rbegin(), t.rend() );
    if( s != t ) return false;

    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int i, len;
    string s;
    bool palindrome, mirrored;

    // Inicializar
    len=pairs.length();
    for(i = 1; i < len; i += 2)
        mirror[pairs[i-1]] = pairs[i];

    while ( getline(cin, s) )
    {
        palindrome = isPalindrome(s);
        mirrored = isMirrored(s);
        if( palindrome && mirrored )
            cout << s << " -- is a mirrored palindrome." << endl;
        else if ( palindrome && !mirrored )
            cout << s << " -- is a regular palindrome." << endl;
        else if ( !palindrome && mirrored )
            cout << s << " -- is a mirrored string." << endl;
        else
            cout << s << " -- is not a palindrome."  << endl;
        cout << endl;
    }

    return 0;
}
