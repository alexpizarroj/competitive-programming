#include <cstdio>
typedef unsigned long long ull;

class Date
{
public:
    int d, y, m;
    ull toDays();
    void fromDays(ull n);
};

ull Date::toDays() {
    ull y, m;

    m = (this->m + 9)%12;
    y = this->y - m/10;

    return y*365 + y/4 - y/100 + y/400 + (m*306 + 5)/10 + (this->d - 1);
}

void Date::fromDays(ull n)
{
    int y, ddd, mi;

    y = (n*10000 + 14780)/3652425;
    ddd = n - (y*365 + y/4 - y/100 + y/400);
    if (ddd < 0) {
        y--;
        ddd = n - (y*365 + y/4 - y/100 + y/400);
    }
    mi = (52 + 100*ddd)/3060;

    this->y = y + (mi + 2)/12;
    this->m = (mi + 2)%12 + 1;
    this->d = ddd - (mi*306 + 5)/10 + 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n; Date d;
	while ( scanf("%d %d %d %d", &n, &d.d, &d.m, &d.y), ( n || d.d || d.m || d.y) )
	{
	    d.fromDays( d.toDays() + n );
	    printf("%d %d %d\n", d.d, d.m, d.y);
	}

    return 0;
}
