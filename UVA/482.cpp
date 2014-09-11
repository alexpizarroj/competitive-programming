// IO
#include <iostream>
#include <cstdio>
// STL
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;
// STRINGS
#include <string>
#include <cstring>
// OTROS
#include <cstdlib>
#include <memory.h>
#include <cmath>
// MACROS
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()


int main() {
    //freopen("data.in", "r", stdin);

    vector<string> v, v2;
    vector<int> order;
    char *pc, *cbuffer;
    string buffer, element;
    int n, i, T;
    bool firstcase = true;

    scanf("%d", &T); getchar();
    while( T-- )
    {
        getchar();

        order.clear();
        getline(cin, buffer);
        cbuffer = new char[buffer.length()+1];
        strcpy(cbuffer, buffer.c_str());
        n = 0;
        pc = strtok(cbuffer, " ");
        while ( pc != NULL )
        {
            sscanf(pc, "%d", &i);
            order.push_back(i);
            pc = strtok(NULL, " ");
            n++;
        }
        delete[] cbuffer;

        v.clear();
        for(i=0; i<n; i++)
        {
            cin >> element;
            v.push_back(element);
        }
        getchar();

        if( !firstcase ) puts("");
        v2.resize( v.size() );
        for(i=0; i<n; i++)
            v2[ order[i]-1 ] = v[i];
        for(i=0; i<n; i++)
            cout << v2[i] << endl;
        firstcase = false;
    }

    return 0;
}
