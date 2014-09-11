#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    char input[100];

    while ( gets(input) && input[0] != '#' )
    {
        if( next_permutation(input, input+strlen(input)) )
            printf("%s\n", input);
        else
            puts("No Successor");
    }

    return 0;
}

/*
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define NoAns cout << "No Successor" << endl
#define NotSet 30
using namespace std;


int main() {
    char in[50];        //Input
    int len;            //Input len
    bool found;         //
    char min;           //
    int diff, tdiff;    //
    int i,j,k,l;        //Contadores
    char* ans;

    while (true) {
        cin >> in;
        if(in[0]=='#') break;
        len=strlen(in);
        if(len==1) NoAns; else {
            ans=new char[len+1];
            found=false;
            j=len-2;
            while (!found && j>=0) {
                min=in[j]; diff=NotSet;
                for(i=j+1;i<len;i++) {
                    tdiff=in[i]-min;
                    if(tdiff>0 && tdiff<diff) diff=tdiff;
                    if(diff==1) break;
                }
                // Encontramos una posición para permutar
                if(diff!=NotSet) {
                    // Copiamos el inicio de la cadena hasta antes del cambio
                    for(k=0;k<j;k++) {ans[k]=in[k];}
                    ans[k]=in[i];
                    if(len==2) ans[k+1]=in[j]; else {
                        // Código para cadenas largas
                        l=j+1;
                        for(k=j;k<len;k++) {
                            if(k!=i) {
                                ans[l]=in[k];
                                l++;
                            }
                        }
                        sort(ans+j+1,ans+len);
                    }
                    ans[len]=0;
                    // Salimos...
                    found=true;
                }
                j--;
            }
            if(found) cout << ans << endl; else NoAns;
        }
    }

    return 0;
}
*/