#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#include <map>
#define PB push_back
#define fup(i,a,b) for(int i = (a); (i) < int(b); ++i)
using namespace std;

const int REDUCE = 1e4;
map<char,char> opp;
int dp[105][105], inter[105][105];
string s, t;

int solve(int a, int b)
{
    if ( a > b ) return 0;
    int &ans = dp[a][b];
    
    if ( ans == -1 )
    {
        if ( a == b )
            ans = 1;
        else 
        {
            ans = 1e3;
            if ( (s[a] == '(' || s[a] == '[') && s[a] == opp[s[b]] ) 
            {
                ans = solve(a+1, b-1), inter[a][b] = REDUCE;
            }
            fup(i,a,b)
            {
                int candidate = solve(a,i) + solve(i+1,b);
                if ( candidate < ans ) ans = candidate, inter[a][b] = i;
            }
        }
    }
    
    return dp[a][b];
}

void backtrack(int a, int b, int c, int d)
{
    if ( a > b ) return;
    
    if ( a == b ) 
    {
        t[c] = s[a];
        t[d] = opp[s[a]];
        if ( t[c] > t[d] ) swap(t[c], t[d]);
    }
    else if ( inter[a][b] == REDUCE )
    {
        t[c] = s[a], t[d] = s[b];
        backtrack(a+1, b-1, c+1, d-1);
    }
    else
    {
        int k = inter[a][b];
        backtrack(a, k, c, c+(k-a+1)+dp[a][k]-1);
        backtrack(k+1, b, d-(b-k)-dp[k+1][b]+1, d);
    }
}

/*
string testgen(int str_size)
{
    char mp[4] = {'(', '[', ']', ')'};
    string test;
    
    test.resize(str_size);
    fup(i,0,str_size) test[i] = mp[rand()%4];
    
    return test;
}

bool isOk(string s)
{
    string ans = "";
    stack<char> st;
    
    fup(i,0,s.size())
    {
        char c = s[i];
        if ( c == '(' || c == '[' )
        {
            st.push(c);
        }
        else
        {
            while ( !st.empty() && st.top() != opp[c] )
            {
                char d = st.top(); st.pop();
                ans.PB(opp[d]);
            }
            if ( st.empty() ) ans.PB(opp[c]);
            else              st.pop();
        }
        ans.PB(c);
    }
    while ( !st.empty() )
    {
        char c = st.top(); st.pop();
        ans.PB(opp[c]);
    }

    return (ans.size() != s.size());
}
*/

int main()
{
    opp['('] = ')', opp[')'] = '(', opp['['] = ']', opp[']'] = '[';
    
    while ( getline(cin,s), cin )
    {
        memset(dp, -1, sizeof dp);
        t.assign( s.size() + solve(0,s.size()-1), '0' );
        backtrack(0, s.size()-1, 0, t.size()-1);
        cout << t << endl;
    }
    
    /*
    puts("Testing mode");
    srand(time(NULL));
    while ( true )
    {
        s = testgen(5);
        memset(dp, -1, sizeof dp);
        t.assign( s.size() + solve(0,s.size()-1), '0' );
        backtrack(0, s.size()-1, 0, t.size()-1);
        cout << t << endl;
        if ( !isOk(t) ) 
        {
            cout << "WA for " << s << endl;
            break;
        }
    }
    */
	
    return 0;
}
