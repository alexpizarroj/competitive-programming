#include <iostream>
#include <string>
using namespace std;

string ans;

void solve(string pre, string in)
{
    if (pre.size() == 0 || in.size() == 0) return;
    
    int n = pre.size(), i = in.find(pre[0]);
    solve(pre.substr(1,i), in.substr(0, i));
    solve(pre.substr(i+1, n), in.substr(i+1,n));
    ans.push_back(pre[0]);
}

int main()
{    
    string pre, in, pos;
    int cases, n;
    
    cin >> cases;
    while (cases--)
    {
        cin >> n >> pre >> in;
        ans.clear();
        solve(pre, in);
        cout << ans << endl;
    }
    
    return 0;
}
