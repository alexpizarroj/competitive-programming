#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define MAXSTRLEN 1001
#define PCI pair<char, int>
#define MAP vector< PCI >

using namespace std;

static MAP v;
static PCI *p;
static int len, i, j;

void add(const char c) {
    int len = v.size();
    for(j = 0; j != len; j++) if(v[j].first == c) { v[j].second++; return; }
    //
    p = new PCI; (*p).first = c; (*p).second = 1;
    v.push_back(*p);
}

bool compfunc(PCI x, PCI y) {
    if(x.second != y.second) return x.second > y.second;
    return x.first < y.first;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	MAP::iterator it;
	int N; char s[MAXSTRLEN];
	memset(s, 0, MAXSTRLEN);

    // Entrada y solucion
	scanf("%d", &N); getchar();
	while (N--) {
        gets(s); len = strlen(s);
        for (i = 0; i != len; i++) if( isalpha(s[i]) ) add(toupper(s[i]));
	}
	sort(v.begin(), v.end(), compfunc);
	// Salida
	for(it = v.begin(); it != v.end(); it++) printf("%c %d\n", (*it).first, (*it).second);

    return 0;
}
