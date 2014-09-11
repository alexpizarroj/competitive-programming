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
using namespace std;
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define SET(a,v) memset(a, v, sizeof(a))
#define PB push_back
#define MP make_pair
#define PI acos(-1)
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define range(v) (v).begin(), (v).end()
#define len(a) (int)(a).length()
#define sz(a) (int)(a).size()
#define sqr(a) (a)*(a)
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


#define Vector Point
struct Point
{
    double x,y;
    Point() {}
    Point(double _x, double _y)      { x=_x; y=_y; }
    Point operator-(const Point& p)  { return Point(x-p.x, y-p.y); }
};
double cross(const Vector& a, const Vector& b) { return (a.x * b.y) - (a.y * b.x); }
int sign(double x) { if( x == 0 ) return 0; return ( x>0 ? 1 : -1 ); }


class CFigure
{ public: virtual bool Contains(double x, double y) =0; };

class CRect : public CFigure
{
    protected:
        double x1,x2,y1,y2;
    public:
        CRect(double _x1, double _y1, double _x2, double _y2)
        {
            x1=min(_x1,_x2); x2=max(_x1,_x2);
            y1=min(_y1,_y2); y2=max(_y1,_y2);
        }
        bool Contains(double x, double y)
        { return ( x1 < x && x < x2 ) && ( y1 < y && y < y2 ); }
};

class CCircle : public CFigure
{
    protected:
        double cx,cy,r;
    public:
        CCircle(double _cx, double _cy, double _r)
        { cx=_cx; cy=_cy; r=_r; }
        bool Contains(double x, double y)
        {
            if ( cx-r < x && x < cx+r )
            {
                double h = sqrt( sqr(r) - sqr(x-cx) );
                return ( cy-h < y && y < cy+h );
            }
            return false;
        }
};

class CTriangle : public CFigure
{
    protected:
        Vector AB,BC,CA;
        Point A,B,C;
    public:
        CTriangle(Point a, Point b, Point c)
        {
            AB = (b-a); BC = (c-b); CA = (a-c);
            A = a; B = b; C = c;
        }
        bool Contains(double x, double y)
        {
            Point P(x,y);
            Vector AP = (P-A), BP = (P-B), CP = (P-C);
            double c[3];
            c[0]=cross(AB,AP); c[1]=cross(BC,BP); c[2]=cross(CA,CP);
            return sign(c[0]) == sign(c[1]) && sign(c[1]) == sign(c[2]);
        }
};

#define END_VAL 9999.9
char line[101];
int main() {
	#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
	#endif

    double x,y,x2,y2,x3,y3,r;
    vector<CFigure*> v;
    size_t i, currentPoint=1;

    gets(line);
    while( line[0] != '*' )
    {
        switch( line[0] )
        {
            case 'r':
            {
                sscanf(line, "%*c %lf %lf %lf %lf", &x, &y, &x2, &y2);
                v.push_back( new CRect(x,y,x2,y2) );
                break;
            }
            case 'c':
            {
                sscanf(line, "%*c %lf %lf %lf", &x, &y, &r);
                v.push_back( new CCircle(x,y,r) );
                break;
            }
            case 't':
            {
                sscanf(line, "%*c %lf %lf %lf %lf %lf %lf", &x, &y, &x2, &y2, &x3, &y3);
                v.push_back( new CTriangle(
                                           Point(x,y),Point(x2,y2),Point(x3,y3)
                                           ) );
                break;
            }
        }
        gets(line);
    }

    while( scanf("%lf %lf", &x, &y), x!=END_VAL && y!=END_VAL )
    {
        bool contained=false;
        FOR(i,v.size())
        {
            if( v[i]->Contains(x,y) )
            {
                contained=true;
                printf("Point %d is contained in figure %d\n", currentPoint, i+1);
            }
        }
        if(!contained)
            printf("Point %d is not contained in any figure\n", currentPoint);

        currentPoint++;
    }

    return 0;
}
