#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#define PB 				        push_back
#define F                       first
#define S                       second
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define dall(a)		 	        (a).begin(), (a).end()
#define dinit(a) 		        memset(a, -1, sizeof(a))
#define dclr(a)         	 	memset(a, 0, sizeof(a))
#define dbet(lb,v,ub)			(lb <= v && v <= ub)
using namespace std; const int INF = int(1E9+7);
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> ii; typedef vector<int> vi;

#define vector_t point_t
#define EPS 1E-6
inline bool fequal(double x, double y) { return abs(x-y) < EPS; }

class point_t
{
public:
    point_t() {}
    point_t(double x, double y) : x(x), y(y) {}
    double x, y;
    double mod() { return hypot(x,y); }
    point_t unit() { double m = mod(); return point_t(x/m, y/m); }
    point_t ort() { return point_t(-y, x); }
};

inline point_t operator+(const point_t& a, const point_t& b) { return point_t(a.x+b.x, a.y+b.y); }
inline point_t operator-(const point_t& a, const point_t& b) { return point_t(a.x-b.x, a.y-b.y); }
inline point_t operator*(const point_t& a, double k) { return point_t(a.x*k, a.y*k); }
inline double dist(const point_t& a, const point_t& b) { return hypot(a.x-b.x, a.y-b.y); }

class line_t
{
public:
    line_t() {}
    line_t(const point_t& pt1, const point_t& pt2)
    {
        this->fromPoints(pt1, pt2);
    }
    double a, b, c;
    void fromPoints(const point_t& pt1, const point_t& pt2)
    {
        a = pt2.y - pt1.y;
        b = pt1.x - pt2.x;
        c = (pt2.x - pt1.x) * pt1.y - (pt2.y - pt1.y) * pt1.x;
    }
};

inline bool parallel(const line_t& l1, const line_t& l2) { return fequal(l1.a * l2.b, l1.b * l2.a); }
inline point_t intersection(const line_t& l1, const line_t& l2)
{
    const double &a = l1.a, &b = l1.b, &c = l1.c;
    const double &d = l2.a, &e = l2.b, &f = l2.c;
    return point_t( (b*f-c*e)/(a*e-b*d), (f*a-c*d)/(b*d-a*e) );
}
inline bool pointIsOnSegment(const point_t &a, const point_t &b, const point_t &p)
{
    double x1 = a.x, x2 = b.x, y1 = a.y, y2 = b.y;
    vector_t v = (a - b).ort();
    line_t A(a, b), B(p, p+v);
    bool isOn = false;

    if( x1 > x2 ) swap(x1, x2);
    if( y1 > y2 ) swap(y1, y2);
    if( dbet(x1, p.x, x2) && dbet(y1, p.y, y2) )
    {
        v = intersection(A,B);
        if( fequal(p.x, v.x) && fequal(p.y, v.y) )
            isOn = true;
    }

    return isOn;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

    point_t m, bestPoint;
    vector<point_t> segments;
    double bestDist, d;
    line_t A, B;
    vector_t v;
    int n;


    while ( scanf("%lf %lf", &m.x, &m.y) != EOF )
    {
        // Input reading
        segments.clear();
        scanf("%d", &n);
        for(int i = 0; i <= n; i++)
        {
            point_t p;
            scanf("%lf %lf", &p.x, &p.y);
            segments.PB(p);
        }
        bestDist = dist(m, segments[0]);
        bestPoint = segments[0];

        // Processing
        for(int i = 1; i <= n; i++)
        {
            // Segment extremes
            if( (d = dist(m,segments[i])) < bestDist )
            {
                bestDist = d, bestPoint = segments[i];
            }
            if( (d = dist(m,segments[i-1])) < bestDist )
            {
                bestDist = d, bestPoint = segments[i-1];
            }
            // Distance to best projection in segment
            v = (segments[i] - segments[i-1]).ort();
            A.fromPoints(segments[i], segments[i-1]);
            B.fromPoints(m, m + v);
            if ( !parallel(A, B) )
            {
                point_t inter( intersection(A, B) );
                if ( pointIsOnSegment(segments[i], segments[i-1], inter) )
                {
                    if( (d = dist(m,inter)) < bestDist )
                    {
                        bestDist = d, bestPoint = inter;
                    }
                }
            }
        }

        // Output
        printf("%.4lf\n%.4lf\n", bestPoint.x, bestPoint.y);
    }

    return 0;
}
