// includes {
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
#include <cmath>
#include <climits>
#include <cctype>
// }
using namespace std;
// defines {
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define TOK(pc, s, tokens) for(char* pc = strtok(s, tokens); pc != NULL; pc = strtok(NULL,tokens))
#define SZ(a) (int)(a).size()
#define LEN(a) (int)(a).length()
#define PB push_back
#define MP make_pair
#define all(a) (a).begin(), (a).end()
#define sqr(a) (a)*(a)
#define inrange(lb,i,ub) ((lb) <= (i) && (i) <= (ub))
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// }
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};


#define Vector Point
struct Point
{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    double arg()  { return atan2(y, x); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

bool sameLine(Point P1, Point P2, Point P3, Point P4)
{ return area(P1, P2, P3) == 0 && area(P1, P2, P4) == 0; }

bool isParallel(const Point &P1, const Point &P2, const Point &P3, const Point &P4)
{ return cross(P2 - P1, P4 - P3) == 0; }

Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{ return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C)); }


int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

	Point A,B,C,D;
	bool parallel, same;
	int n;

    puts("INTERSECTING LINES OUTPUT");
	scanf("%d",&n);
	while(n--)
	{
	    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y,
           &C.x, &C.y, &D.x, &D.y);
        parallel = isParallel(A,B,C,D);
        same = sameLine(A,B,C,D);
        if( same )
            puts("LINE");
        else if ( parallel )
            puts("NONE");
        else
        {
            Point p = lineIntersection(A,B,C,D);
            printf("POINT %.2lf %.2lf\n", p.x, p.y);
        }
	}
	puts("END OF OUTPUT");

    return 0;
}
