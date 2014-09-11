#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;

string binaryToStr(size_t n)
{
    string ret;
    do {
        ret = char((n%2)+'0') + ret;
        n /= 2;
    } while (n > 0);
    return ret;
}

int maskModVal(size_t n, int m)
{
    int val = 0, mult = 1%m;
    do {
        val = (val + (n%2)*mult)%m;
        mult = (mult * 10)%m;
        n /= 2;
    } while (n > 0);
    return val;
}

int main()
{
    const int cMax = 200, cMaskMax = 1<<21;
    bool done[cMax+1];
    map<int, string> sol;
    int nSolved = 0, mask = 1;
    
    // Precalculation
    memset(done, false, sizeof done);
    while ( nSolved < cMax && mask < cMaskMax )
    {
        for(int i = 1; i <= cMax; i++)
        {
            if ( done[i] ) continue;
            if ( maskModVal(mask,i) == 0 )
            {
                done[i] = true;
                sol[i] = binaryToStr(mask);
                nSolved++;
            }
        }
        mask++;
    }
    
    /*
    cout << "I haved solved " << nSolved << endl;
    cout << "I used " << binaryToStr(mask-1).size() << " digits" << endl;
    for(int i = 1; i <= cMax; i++) printf("%03d: %s\n", i, sol[i].c_str());
    */
    
    // Input processing
    int X;
    while ( scanf("%d", &X), X > 0 )
        printf("%s\n", sol[X].c_str());
    
    return 0;
}