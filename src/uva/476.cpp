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
#include <climits>
#include <cctype>
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define PB push_back
#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define set(a,v) memset(a, v, sizeof(a))
#define len(a) (int)(a.length())

#define WILDCARD 9999.9
struct Rectangle {
    Rectangle() {}
    Rectangle(double _x1, double _y1, double _x2, double _y2) {
        x1 = min(_x1,_x2);
        x2 = max(_x1,_x2);
        y1 = min(_y1,_y2);
        y2 = max(_y1,_y2);
    }
    double x1, x2;
    double y1, y2;
};

char line[1001];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    double x, y;
    Rectangle r;
    vector<Rectangle> v;
    int i, currentPoint=1;
    bool contained;

    do {
        gets(line);
        if( line[0] == '*' ) break;
        sscanf(line, "%*c %lf %lf %lf %lf", &r.x1, &r.y1, &r.x2, &r.y2);
        v.push_back( Rectangle(r.x1,r.y1,r.x2,r.y2) );
    } while(1);

    do {
        gets(line);
        sscanf(line, "%lf %lf", &x, &y);
        if( x==WILDCARD && y==WILDCARD ) break;

        contained=false;
        FOR(i,(int)v.size())
        {
            Rectangle &rec = v[i];
            if( rec.x1 < x && x < rec.x2 && rec.y1 < y && y < rec.y2 )
            {
                printf("Point %d is contained in figure %d\n", currentPoint, i+1);
                contained = true;
            }
        }

        if(!contained)
            printf("Point %d is not contained in any figure\n", currentPoint);
        currentPoint++;
    }while(1);

    return 0;
}
