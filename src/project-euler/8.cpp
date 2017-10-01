#include <iostream>
#include <string>
using namespace std;

int main()
{
    int ans, cand;
    string n = "", str;
    
    while ( cin >> str ) n += str;
    //cout << n.size() << endl;
    
    ans = 0;
    for(int i = 0; i+4 < (int)n.size(); i++)
    {
        cand = 1;
        for(int j = i; j < i+5; j++) cand *= n[j]-'0';
        if ( cand > ans ) ans = cand;
    }
    cout << ans << endl;

    return 0;
}