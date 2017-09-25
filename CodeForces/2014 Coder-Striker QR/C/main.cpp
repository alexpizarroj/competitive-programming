#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
struct Player { int atk, def; };

int simulate(int atk, int def, Player c, Player d)
{
    Player e1 = {c.atk, d.def}, e2 = {d.atk, c.def};
    
    if ( atk > max(e1.def, e2.def) && def > max(e1.atk, e2.atk) )
        return  1; // Team 1 wins
    else if ( (atk < e1.def && def < e1.atk) || (atk < e2.def && def < e2.atk) )
        return -1; // Team 2 wins
    
    return 0; // Draw
}

int main()
{
    Player a, b, c, d;
    int mr1, mr2;
    
    while ( cin >> a.def >> a.atk >> b.def >> b.atk
            >> c.def >> c.atk >> d.def >> d.atk )
    {
        mr1 = simulate(a.atk, b.def, c, d);
        mr2 = simulate(b.atk, a.def, c, d);
        if ( mr1 == 1 || mr2 == 1 )         puts("Team 1");
        else if ( mr1 == -1 && mr2 == -1 )  puts("Team 2");
        else                                puts("Draw");
    }
    
    return 0;
}
