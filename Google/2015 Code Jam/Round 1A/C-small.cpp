#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const double PI = acos(-1);

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
typedef Point Vector;

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

bool operator ==(const Point &a, const Point &b)
{
    return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b)
{
    return !(a==b);
}
bool operator <(const Point &a, const Point &b)
{
    if(abs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y + EPS < b.y;
}

double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

bool between(const Point &A, const Point &B, const Point &P)
{
    return  P.x + EPS >= min(A.x, B.x) && P.x <= max(A.x, B.x) + EPS &&
            P.y + EPS >= min(A.y, B.y) && P.y <= max(A.y, B.y) + EPS;
}

bool onSegment(const Point &A, const Point &B, const Point &P)
{
    return abs(area(A, B, P)) < EPS && between(A, B, P);
}

vector<Point> convexHull(vector<Point> P)
{
    sort(P.begin(),P.end());
    int n = P.size(),k = 0;
    Point H[2*n];
    
    for(int i=0;i<n;++i){
        while(k>=2 && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && area(H[k-2],H[k-1],P[i]) <= 0) --k;
        H[k++] = P[i];
    }
    
    return vector<Point>(H, H + k - 1);
}

bool isOnBorder(const vector<Point> &ch, const Point &p)
{
  for(int i = 0; i < (int)ch.size(); i++)
  {
    int j = (i + 1) % (int)ch.size();
    if (onSegment(ch[i], ch[j], p))
    {
      return true;
    }
  }
  return false;
}

int main()
{
  int T;
  cin >> T;
  
  for(int test = 1; test <= T; test++)
  {
    int n;
    cin >> n;

    vector< vector<Point> > ss(
      1 << n, vector<Point>()
    );
    vector< vector<Point> > ch = ss;

    for(int i = 0; i < n; i++)
    {
      Point p;
      cin >> p.x >> p.y;
      ss[0].push_back(p);
    }
    ch[0] = convexHull(ss[0]);

    for(int removed = 1; removed < (1<<n) - 1; removed++)
    {
      for(int i = 0; i < n; i++)
      {
        if ( ((removed >> i) & 1) == false )
        {
          ss[removed].push_back(ss[0][i]);
        }
      }
      ch[removed] = convexHull(ss[removed]);
    }

    vector<int> ans(n, 1000);
    for(int removed = 0; removed < (1 << n) - 1; removed++)
    {
      int cnt = __builtin_popcount(removed);
      for(int i = 0; i < n; i++)
      {
        if ((removed >> i) & 1)
        {
          continue;
        }
        if (isOnBorder(ch[removed], ss[0][i]))
        {
          ans[i] = min(ans[i], cnt);
        }
      }
    }

    cout << "Case #" << test << ":\n";
    for(int i = 0; i < n; i++)
    {
      //cout << "(" << ss[0][i].x << ", " << ss[0][i].y << ") ->";
      cout << ans[i] << '\n';
      assert(ans[i] != 1000);
    }
  }

  return 0;
}