#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <memory.h>
#include <cmath>
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()
#define SET(a,v) memset(a, v, sizeof(a))
#define LEN(s) (int)s.length()


inline bool hasHigherPrecendence(char a, char b)
{
    return (a == '*' || a == '/') && (b == '+' || b == '-');
}

inline bool hasEqualPrecendence(char a, char b)
{
    bool predA = (a == '*' || a == '/') && (b == '*' || b == '/');
    bool predB = (a == '+' || a == '-') && (b == '+' || b == '-');
    return predA || predB;
}

inline bool isOperation(char a)
{
    return (a == '*' || a == '/' || a == '+' || a == '-');
}

string toPostfix(string expr)
{
    stack<char> s;
    string postfix = "";
    int i;

    for(i=0; i<LEN(expr); i++)
    {
        const char &c = expr[i];

        if( c >= '0' && c <= '9' )
            postfix += c;
        else if( c == '(' )
            s.push(c);
        else if( isOperation(c) )
        {
            while( !s.empty() )
            {
                if( hasHigherPrecendence(s.top(), c) )
                {
                    postfix += s.top();
                    s.pop();
                }
                else
                    break;
            }
            s.push(c);
        }
        else // if( c == ')' )
        {
            while( !s.empty() && s.top() != '(' )
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while( !s.empty() )
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    string expr, prevExpr = "";
    int t; char c;
    bool firstcase = true;

    scanf("%d", &t); getchar();
    getchar();
    while ( t-- )
    {
        expr = "";
        while( scanf("%c", &c) != EOF && c != '\n' )
        {
            expr += c;
            getchar();
        }

        if( !firstcase && prevExpr != expr ) puts("");
        cout << toPostfix(expr) << endl;
        prevExpr = expr;
        firstcase = false;
    }

    return 0;
}
