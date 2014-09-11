#include <stdio.h>
#include <algorithm>
#include <list>

using namespace std;

static int i;
static list<int> l;

inline list<int>::iterator lget(int pos, list<int>::iterator begin) { list<int>::iterator it = begin; while(pos--) it++; return it; }

list<int>::iterator binlookup(list<int>::iterator it, const int n, const int val, bool *found) {
    // Casos base
    if (n == 1) {
        if (*it == val) {
            *found = true;
            return it;
        } else {
            *found = false;
            return (*it < val ? ++it : it);
        }
    } else if (n == 2) {
        i = *lget(1, it);
        if (*it == val || i == val) {
            *found = true;
            return (*it == val ? it : ++it);
        } else {
            *found = false;
            if (val < *it) return it;
            else if (val < i) return ++it;
            else { it++; return ++it; }
        }
    }
    // Busqueda binaria
    bool even = (n%2 == 0); int mid = n / 2;
    list<int>::iterator p = lget(mid, it);
    if(*p == val) {
        *found = true;
        return p;
    } else if (val < *p) {
        return binlookup(it, mid, val, found);
    } else {
        p++; return binlookup(p, mid-(even?1:0), val, found);
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n = 1, a;
    bool found;
    list<int>::iterator it;

    scanf("%d", &a);
    l.push_back(a);
    printf("%d\n", a);
    while (scanf("%d", &a) != EOF) {
        it = binlookup(l.begin(), n, a, &found);
        if(it == l.end()) {
            l.push_back(a);
        } else {
            l.insert(it, a);
        }
        n++;
        it = lget(n/2, l.begin()); i = *it;
        if(n%2 == 0) { it--; i = (i + *it) / 2; }
        printf("%d\n", i);
    }

    return 0;
}

