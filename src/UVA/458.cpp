#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cstring>
#define maxstrlen 1025

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    char input[maxstrlen];
    int len, i;

    memset(input, 0, maxstrlen);
    while( gets(input) ) {
        len = strlen(input);
        for(i = 0; i != len; i++) input[i] -= 7;
        printf("%s\n", input);
    }

    return 0;
}
