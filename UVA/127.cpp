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

vector< vector<string> > piles;
const int nMaxCards = 52;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	string card;
	int nPiles, back1, back3;
	bool moveFound;
	vector<int> backPtrs;

	while ( cin >> card, card[0] != '#' )
	{
	    // Input
	    piles.assign( nMaxCards+1, vector<string>() );
	    piles[1].PB( card );
	    fupi(i,2,nMaxCards)
	    {
	        cin >> card;
            piles[i].PB( card );
	    }

	    // Debug
	    //fupi(i,1,nMaxCards) cout << (i > 1 ? " " : "") << piles[i].back(); cout << endl;

	    // Processing
        moveFound = true;
        backPtrs.clear();
        while ( moveFound )
        {
            moveFound = false;
            for(int i = 1; i <= nMaxCards && !moveFound; i++)
            {
                if( piles[i].size() == 0 ) continue;
                const string& ref = piles[i].back();

                // Move checking, from left to right
                back1 = ( backPtrs.size() >= 1 ? backPtrs[backPtrs.size()-1] : -1 );
                back3 = ( backPtrs.size() >= 3 ? backPtrs[backPtrs.size()-3] : -1 );
                if( back3 > -1 && ( piles[back3].back()[0] == ref[0] || piles[back3].back()[1] == ref[1] ) )
                {
                    moveFound = true;
                    piles[back3].PB( ref );
                    piles[i].pop_back();
                }
                else if( back1 > -1 && ( piles[back1].back()[0] == ref[0] || piles[back1].back()[1] == ref[1] ) )
                {
                    moveFound = true;
                    piles[back1].PB( ref );
                    piles[i].pop_back();
                }

                // Back pointers
                if( !moveFound )
                {
                    if( backPtrs.size() < 3 )
                        backPtrs.PB(i);
                    else
                    {
                        swap( backPtrs[0], backPtrs[1] );
                        swap( backPtrs[1], backPtrs[2] );
                        backPtrs[2] = i;
                    }
                }
            }
            backPtrs.clear();
        }

	    // Output
	    nPiles = 0;
	    fupi(i,1,nMaxCards) if ( piles[i].size() > 0 ) nPiles++;
	    cout << nPiles << " pile" << ( nPiles > 1 ? "s" : "") << " remaining:";
	    fupi(i,1,nMaxCards) if ( piles[i].size() > 0 ) printf(" %d", piles[i].size());
	    puts("");
	}

    return 0;
}
