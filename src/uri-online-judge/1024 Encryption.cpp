#include <cstdio>
#include <cstring>
#include <cctype>

int main()
{
    int n, len;
    char line[1005], aux;
    
    scanf("%d", &n); getchar();
    while ( n-- )
    {
        gets(line);
        len = strlen(line);
        for(int i = 0; i < len; ++i)
            if ( isalpha(line[i]) ) line[i] += 3;
        for(int i = 0, j = len-1; i < j; ++i, --j)
            aux = line[i], line[i] = line[j], line[j] = aux;
        for(int i = (len/2); i < len; ++i)
            line[i] -= 1;
        printf("%s\n", line);
    }
    
    return 0;
}