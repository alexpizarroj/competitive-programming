#include <cstdio>

int main()
{
    int h1, m1, h2, m2;
    scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
    int t1 = h1*60 + m1, t2 = h2*60 + m2, dt = t2 - t1;
    printf("%d horas, %d minutos\n", dt/60, dt%60);
    return 0;
}