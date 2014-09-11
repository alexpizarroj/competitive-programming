#include <cassert>
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
#include <fstream>
#include <bitset>
#define PB 				        push_back
#define MP 				        make_pair
#define fup(i,a,b) 		        for(int i = (a); (i) < int(b); i++)
#define fdo(i,a,b) 		        for(int i = (a); (i) > int(b); i--)
#define fupi(i,a,b) 		    for(int i = (a); (i) <= int(b); i++)
#define fdoi(i,a,b) 		    for(int i = (a); (i) >= int(b); i--)
#define foreach(it, a) 	        for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
#define dall(a)		 	        (a).begin(), (a).end()
#define dset(a,v) 		        memset(a, v, sizeof(a))
#define dclr(a)         	 	memset(a, 0, sizeof(a))
#define least_first_heap(T)     priority_queue<T, deque<T>, greater<T> >
using namespace std;

typedef long long ll; typedef unsigned long long ull; typedef pair<int,int> pii; typedef vector<int> vi;
template<class T> bool inline between(const T& lb, const T& v, const T& ub) { return lb<=v && v<=ub; }
const int INF = int(1E9+7);

map< string, set<string> > mp;
set< string > readValues;
vector<string> output;

string makeKey(const string& s)
{
    string r;

    r.reserve(s.size());
    fup(i,0,s.size())
    {
        if ( s[i] != ' ' ) r.PB(s[i]);
    }
    sort(dall(r));

    return r;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	#endif

	int tc; string sz;

	scanf("%d", &tc); cin.ignore(2);
	for(int caseNo = 0; caseNo < tc; caseNo++)
	{
	    if( caseNo > 0 ) puts("");

	    mp.clear();
	    readValues.clear();
	    while ( getline(cin, sz) != NULL && sz.size() > 0 )
	    {
	        if( readValues.count(sz) == 0 )
	        {
	            mp[ makeKey(sz) ].insert(sz);
	            readValues.insert( sz );
	        }
	    }

        output.clear();
        foreach(it, mp)
        {
            if( it->second.size() > 1 )
            {
                const set<string>& st = it->second;
                foreach(it1, st)
                {
                    typeof(it1) it2 = it1; it2++;
                    for(; it2 != st.end(); it2++ )
                    {
                        output.push_back( *it1 + " = " + *it2 );
                    }
                }
            }
        }
        sort( dall(output) );
        foreach(it, output)
        {
            cout << *it << endl;
        }
	}

    return 0;
}
