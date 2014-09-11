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

struct Array {
    int dimensions;
    int bytesPerElement;
    int baseAddress;
    vector< pair<int,int> > bounds;
    vector<int> c;

    void CalculateConstValues()
    {
        c.resize(dimensions+1);
        c[dimensions] = bytesPerElement;

        for(int i=dimensions-1; i>=1; i--)
        {
            c[i] = c[i+1] * (bounds[i].second - bounds[i].first + 1);
        }

        c[0] = baseAddress;
        for(int i=1; i<=dimensions; i++)
        {
            c[0] -= c[i] * bounds[i-1].first;
        }
    }
};
map<string,Array> definitions;

int main() {
    //freopen("data.in", "r", stdin);

	int N, R, i, j, index, LB, UB;
	string name; char nameBuffer[11];
	vector<int> indexes;

    scanf("%d %d", &N, &R); getchar();
    for(i=0; i<N; i++)
    {
        Array ar;
        scanf("%s %d %d %d", nameBuffer, &ar.baseAddress, &ar.bytesPerElement, &ar.dimensions);
        for(j=0; j<ar.dimensions; j++)
        {
            scanf("%d %d", &LB, &UB);
            ar.bounds.push_back( make_pair(LB, UB) );
        }
        getchar();
        ar.CalculateConstValues();
        definitions[ string(nameBuffer) ] = ar;
    }

    for(i=0; i<R; i++)
    {
        indexes.clear();
        scanf("%s", nameBuffer);
        Array &ar = definitions[ string(nameBuffer) ];
        for(j=0; j<ar.dimensions; j++)
        {
            scanf("%d", &index);
            indexes.push_back(index);
        }

        int address=ar.c[0];
        for(j=1; j<=ar.dimensions; j++)
            address += ar.c[j] * indexes[j-1];

        printf("%s[%d", nameBuffer, indexes[0]);
        for(j=1; j<ar.dimensions; j++)
            printf(", %d", indexes[j]);
        printf("] = %d\n", address);
    }

    return 0;
}
