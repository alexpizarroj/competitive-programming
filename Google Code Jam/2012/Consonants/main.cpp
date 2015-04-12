// {
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
using namespace std;
// } {
#define FOR(i,n) for((i)=0; (i)<(n); (i)++)
#define REP(i,n) for((i)=1; (i)<=(n); (i)++)
#define tokenize(pc, searchString, tokenString) for(char* pc = strtok(searchString, tokenString); pc != NULL; pc = strtok(NULL,tokenString))
#define PB push_back
#define MP make_pair
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(typeof((a).begin()) it=(a).begin(); it != (a).end(); it++)
// } {
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
const int dx[] = {0,0,1,-1,1,1,-1,-1};
const int dy[] = {1,-1,0,0,1,-1,1,-1};
// } {
template<typename T>
bool inline between(const T& lbound, const T& value, const T& ubound)
{ return lbound <= value && value <= ubound; }
// }

char name[101];
bool vowel[101];
inline bool isVowel(char c) { return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'; }

bool hasAtLeastN(int i, int j, int N)
{
    int consecutive=0;
    for(; i<=j && consecutive < N; i++)
    {
        if( !vowel[i] )
        {
            consecutive++;
        }
        else
        {
            consecutive = 0;
        }
    }
    return (consecutive == N);
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int tc, T, n;
	int i, j, len;
	size_t n_value;

	cin >> T;
	REP(tc,T)
	{
        cin >> name >> n;
        len = strlen(name);
        memset(vowel, 0, sizeof vowel);
        for(i=0; i<len; i++)
        {
            vowel[i] = isVowel(name[i]);
        }

        n_value = 0;
        for(i=0; i<len; i++)
        {
            for(j=i; j<len; j++)
            {
                if( hasAtLeastN(i,j,n) )
                {
                    n_value++;
                }
            }
        }
        cout << "Case #" << tc << ": " << n_value << endl;
	}

	fclose(stdout);
    return 0;
}
