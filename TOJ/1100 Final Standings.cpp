#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;

struct Team
{
    Team(int p_id, int p_nProblems) : id(p_id), nProblems(p_nProblems) { }
    int id, nProblems;
};

bool criteria(const Team &lhs, const Team &rhs)
{
    return ( lhs.nProblems > rhs.nProblems );
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    vector<Team> vec;
    int n, id, nProblems;
    while ( scanf("%d", &n) != EOF )
    {
        vec.clear();
        vec.reserve(n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &id, &nProblems);
            vec.push_back( Team(id,nProblems) );
        }

        stable_sort(vec.begin(), vec.end(), criteria);
        for(vector<Team>::iterator it = vec.begin(); it != vec.end(); ++it)
        {
            printf("%d %d\n", it->id, it->nProblems);
        }
    }
    return 0;
}
