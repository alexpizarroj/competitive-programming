#include <iostream>
#include <sstream>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define maxstrlen 121

using namespace std;

static int v[30], vl;

int u_toint(const char* str) {
    int ret;
    stringstream ss(str); ss >> ret;
    return ret;
}

void u_rev(int start) {
    int steps = (start - (start%2 != 0 ? 1 : 0)) / 2;
    int i = 0, j = start-1;
    while(steps--) {
        swap(v[i], v[j]);
        i++; j--;
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	char s[maxstrlen], *c;
	int pancake, pidx, v2[30], vl2, i, len;
	vector<int> steps;
	memset(s, 0, maxstrlen);

	while(gets(s) != NULL) {
	    // Entrada
	    steps.clear();
        memset(v, 0, sizeof(int)*30);
        i = 0; c = strtok(s, " ");
        while (c != NULL) {
            v[i] = u_toint(c);
            c = strtok(NULL, " "); i++;
        }
        vl = i;
        vl2 = vl+1;
        memcpy(v2, v, sizeof(int)*30);
        // Resolucion
        while(vl != 1) {
            pidx = 0; pancake = v[0];
            for(i = 1; i < vl; i++) {
                if (v[i] > pancake)  {
                    pancake = v[i];
                    pidx = i;
                }
            }
            pidx++;
            if (pidx != vl) {
                if(pidx != 1) {
                    steps.push_back(vl2-pidx);
                    u_rev(pidx);
                    pidx = 1;
                }
                steps.push_back(vl2-vl);
                u_rev(vl);

            }
            vl--;
        }
        steps.push_back(0);
        // Salida
        vl2--; len = steps.size();
        for(i = 0; i < vl2; i++) cout << (i == 0 ? "" : " ") << v2[i];
        cout << endl;
        for(i = 0; i < len; i++) cout << (i == 0 ? "" : " ") << steps.at(i);
        cout << endl;
	}

    return 0;
}
