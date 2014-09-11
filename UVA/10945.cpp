#include <cstdio>
#include <cstring>
#include <cctype>
#define MAX 10001

using namespace std;


void ClearSentence(const char *src, char *dst)
{
    int len = 0, size = strlen(src);
    for(int i=0; i<size; i++)
        if( isalpha(src[i]) ) dst[len++] = tolower(src[i]);
    dst[len] = 0;
}

bool isPalindrome(const char *s)
{
    int i=0; int j=strlen(s)-1;
    while(i<j)
    {
        if( s[i] != s[j] ) return false;
        i++;
        j--;
    }
    return true;
}


char buffer[MAX], clean[MAX];
int main()
{
    //freopen("data.in", "r", stdin);
    while( gets(buffer) )
    {
        if( strcmp(buffer, "DONE") ==0 ) break;
        ClearSentence(buffer, clean);
        if( isPalindrome(clean) )
            puts("You won't be eaten!");
        else
            puts("Uh oh..");
    }
    return 0;
}
