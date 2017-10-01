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

Point lineIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return A + (B - A) * (cross(C - A, D - C) / cross(B - A, D - C));
}

Point circumcenter(const Point &A, const Point &B, const Point &C)
{
    Point mc = (A+B)/2, mb = (A+C)/2;
    return lineIntersection(mc, mc+(B-A).ort(), mb, mb+(C-A).ort());
}

inline void printn(char sign, double n)
{
    if( n < 0 )
    {
        if( sign=='+' ) sign='-';
        else            sign='+';
        n *= -1;
    }
    printf("%c %.3lf", sign, n);
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

	Point A,B,C,O;
	double h,k,r, c,d,e;

	while( scanf("%lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y) != EOF )
	{
	    O = circumcenter(A,B,C);
	    h = O.x, k = O.y, r = dist(A,O);
	    c = -(2*h), d = -(2*k), e = (h*h + k*k - r*r);

	    printf("(x ");
	    printn('-',h);
	    printf(")^2 + (y ");
	    printn('-',k);
	    printf(")^2 = %.3lf^2\n", r);

	    printf("x^2 + y^2 ");
	    printn('+',c);
	    printf("x ");
	    printn('+',d);
	    printf("y ");
	    printn('+',e);
	    printf(" = 0\n");;

	    puts("");
	}

    return 0;
}
