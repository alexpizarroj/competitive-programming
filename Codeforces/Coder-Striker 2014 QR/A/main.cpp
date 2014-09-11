#include <cstring>
#include <cctype>
#include <cstdio>
using namespace std;

bool up(char c) { return isupper(c); }
bool lo(char c) { return islower(c); }
bool di(char c) { return isdigit(c); }
bool chk(char *s, int n, bool (*f)(char)) 
{
    bool ok = false;
    for(int i = 0; i < n; i++) if ( f(s[i]) ) { ok = true; break; }
    return ok;
}

int main()
{
    char s[105]; int n;
    while ( scanf("%s", s) != EOF )
    {
        n = strlen(s);
        puts( n>=5 && chk(s,n,up) && chk(s,n,lo) && chk(s,n,di) ?
            "Correct" : "Too weak");
    }
	
    return 0;
}
