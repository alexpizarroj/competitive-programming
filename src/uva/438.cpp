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

#define PI 3.141592653589793
#define Vector Point
struct Point
{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    Point ort()   { return Point(-y, x); }
    double mod()  { return sqrt(x*x + y*y); }
    double mod2() { return x*x + y*y; }
};
Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
inline Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
    { return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C)); }


int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    Point a, b, c;
    Point mc, mb;
    Point center;
    double d;

    while( scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) != EOF )
    {
        mc = (a+b)/2;
        mb = (a+c)/2;
        center = lineIntersection(mc, mc+(b-a).ort(), mb, mb+(c-a).ort());
        d = 2*(center-a).mod();
        printf("%.2lf\n", PI*d );
    }

    return 0;
}
