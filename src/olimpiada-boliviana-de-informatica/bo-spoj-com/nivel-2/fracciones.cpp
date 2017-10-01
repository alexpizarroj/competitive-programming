#include <cstdio>

int main()
{
	int a, b, c, d;
	while ( scanf("%d %d %d %d", &a, &b, &c, &d), a || b || c || d )
	    puts( b * c  ==  a * d ? "=" : "!=");

    return 0;
}
