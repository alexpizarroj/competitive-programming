#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <iomanip>
const double EPS = 1e-6;
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    
    typedef pair<double, double> dd;
    
    int n;
    double fin, ini, p;
    string name, team;
    map< string, dd > m;
    map< string, dd >::iterator it;
    
    while (cin >> n , n!=0)
    {
        m.clear();
        for (int i=0; i<2*n; i++)
        {
            cin >> name >> team >> ini >> fin;
            
            if ( m.count(team) == 0 )
                m.insert( make_pair(team, dd(0.0, 0.0)) );
            
            m[team].first += ini;
            m[team].second += fin;
        }
        
        double mx = -1e4;
        // map keys are already sorted in ascending order,
        // therefore the first max that we get will always
        // be the lexicographically least, thus making a check
        // for ties unnecessary
        for (it = m.begin(); it != m.end(); ++it)
        {
            const dd &w = it->second;
            p = ((w.first - w.second) * 100.0) / w.first;
            if ( p > mx ) 
            {
                team = it->first;
                mx = p;
            }
        }
        
        printf("%s %.1lf%%\n", team.c_str(), mx);
    }
    return 0;
}

