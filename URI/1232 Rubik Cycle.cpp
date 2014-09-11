#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> perm_t;

#define PERM_SZ 21
int cw[PERM_SZ]= { 13,8,3,18,14,9,4,0,19,15,10,5,1,20,16,11,6,2,17,12,7 }; // clock wise perm.
int ccw[PERM_SZ] = { 7,12,17,2,6,11,16,20,1,5,10,15,19,0,4,9,14,18,3,8,13 }; // counter clock wise perm.
// permutable faces with its affeted values
int f[PERM_SZ] = { 16,17,18,3,19,20,21,37,6,22,23,24,40,9,25,26,27,43,28,29,30 };
int r[PERM_SZ] = { 18,15,12,21,37,38,39,46,24,40,41,42,49,27,43,44,45,52,30,33,36 };
int l[PERM_SZ] = { 10,13,16,48,1,2,3,19,51,4,5,6,22,54,7,8,9,25,34,31,28 };
int b[PERM_SZ] = { 12,11,10,39,46,47,48,1,42,49,50,51,4,45,52,53,54,7,36,35,34 };
int u[PERM_SZ] = { 48,47,46,1,10,11,12,39,2,13,14,15,38,3,16,17,18,37,19,20,21 };
int d[PERM_SZ] = { 25,26,27,9,28,29,30,43,8,31,32,33,44,7,34,35,36,45,54,53,52 };
// do-able moves (aka permutations) for the rubik cube
map<char,perm_t> moves;

perm_t makePerm(int *values, int *order)
{
    perm_t ret(PERM_SZ);
    for(size_t i = 0; i < PERM_SZ; i++)
    {
        ret[i].first = values[i], ret[i].second = values[ order[i] ];
    }
    return ret;
}

vector<int> getCubePerm(const char *seq)
{
    vector<int> ret(55), tmp(55);
    for(size_t i = 0; i < ret.size(); i++) ret[i] = i;
    for(size_t len = strlen(seq), i = 0; i < len; i++)
    {
        const perm_t& p = moves[seq[i]];
        for(size_t j = 0; j < ret.size(); j++) tmp[j] = ret[j]; // back up
        for(size_t j = 0; j < p.size(); j++) ret[ p[j].first ] = tmp[ p[j].second ]; // then permute
    }
    return ret;
}

int gcd(int a, int b)
{
    int r;
    while ( b > 0 )
    {
        r = a%b, a = b, b = r;
    }
    return a;
}

inline int lcm(int a, int b)
{
    return ( (a / gcd(a,b)) * b);
}

int gcdOfCyclesLen(const vector<int> &p)
{
    int ret = 1, cnt = 0;
    vector<bool> used(0, p.size());
    size_t i, j;
    for(i = 1; i < p.size(); i++)
    {
        if ( !used[i] )
        {
            used[i] = true, cnt++, j = p[i];
            while ( j != i )
            {
                used[j] = true, cnt++, j = p[j];
            }
            ret = lcm(cnt, ret), cnt = 0;
        }
    }
    return ret;
}

int main()
{
	#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	#endif

    // Moves Init
    moves['U'] = makePerm(u,cw), moves['u'] = makePerm(u,ccw);
    moves['F'] = makePerm(f,cw), moves['f'] = makePerm(f,ccw);
    moves['D'] = makePerm(d,cw), moves['d'] = makePerm(d,ccw);
    moves['R'] = makePerm(r,cw), moves['r'] = makePerm(r,ccw);
    moves['L'] = makePerm(l,cw), moves['l'] = makePerm(l,ccw);
    moves['B'] = makePerm(b,cw), moves['b'] = makePerm(b,ccw);

    // Main Start
    char input[85];
    while ( gets(input) != NULL )
    {
        printf("%d\n", gcdOfCyclesLen(getCubePerm(input)));
    }
    return 0;
}
