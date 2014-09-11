#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define PB 				        push_back
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    typedef pair<int,int> doll_t;
	int t, m, w, h, group;
	vector<doll_t> vec;
	multiset<int> heads;
	multiset<int>::iterator sit;
	vector<int> aux;

	scanf("%d", &t);
	while ( t-- )
	{
	    vec.clear(); heads.clear(); aux.clear();
        scanf("%d", &m);
        fup(i,0,m)
        {
            scanf("%d %d", &w, &h);
            vec.PB( make_pair(w,h) );
        }
        sort( vec.begin(), vec.end(), greater<doll_t>() );
        group = vec[0].first;
        fup(i,0,m)
        {
            if ( vec[i].first != group )
            {
                foreach(it,aux) heads.insert( *it ); aux.clear();
                group = vec[i].first;
            }
            sit = heads.upper_bound(vec[i].second);
            if ( sit != heads.end() )
            {
                heads.erase(sit);
            }
            aux.PB( vec[i].second );
        }
        printf("%d\n", heads.size() + aux.size());
	}

    fclose(stdout);
    return 0;
}
