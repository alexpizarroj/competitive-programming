#include <iostream>
#include <algorithm>
using namespace std;

long long isqrt(long long n)
{
	long long lo = 1, hi = 45000, mid;
	while ( lo < hi )
	{
		mid = (lo + hi)/2 + ((lo + hi)&1);
		if ( mid*mid > n )
			hi = mid - 1;
		else
		 	lo = mid;
	}
	return lo;
}

struct Rect
{
	int x1, x2, y1, y2;
	long long getArea() const
	{
		return (long long)(x2 - x1) * (y2 - y1);
	}
	bool operator<(const Rect &rhs) const
	{
		if ( x1 != rhs.x1 )
			return x1 < rhs.x1;
		return y1 < rhs.y1;
	}
	bool contains(const Rect &r)
	{
		return  (x1 <= r.x1) && (r.x2 <= x2) 
		     && (y1 <= r.y1) && (r.y2 <= y2);
	}
};

int main()
{
	int n;
	Rect re[5];
	while ( cin >> n )
	{
		long long area = 0, side;
		for(int i = 0; i < n; i++)
		{
			cin >> re[i].x1 >> re[i].y1 >> re[i].x2 >> re[i].y2;
			area += re[i].getArea();
		}
		side = isqrt(area);
		
		bool ans = false;
		if ( side*side == area )
		{
			sort(re, re+n);
			Rect target = re[0];
			target.x2 = target.x1 + side;
			target.y2 = target.y1 + side;
			ans = true;
			for(int i = 0; i < n; i++)
				ans &= target.contains(re[i]);
		}
		puts(ans ? "YES" : "NO");
	}
}