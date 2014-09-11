#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#define maxstrlen 256

using namespace std;

struct AP {
    AP(int pstart, int pend) :
        start(pstart), end(pend) {}
    AP(int s1, int s2, int e1, int e2) :
        start( (s1-10)*60 + s2 ), end( (e1-10)*60 + e2 ) {}
    //
    int start, end;
};
bool compareAP (AP i, AP j) {
    if(i.start != j.start) return (i.start < j.start);
    return (i.end < j.end);
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif

    vector<AP> v;
    vector<AP>::iterator it1, it2;
	int dayNo = 1, no, s1, s2, e1, e2, ans, ansStart, i;
	char buffer[maxstrlen]; memset(buffer, 0, maxstrlen);

	while (scanf("%d\n", &no) != EOF) {
	    // Entrada
	    ans = 1;
	    ansStart = 481;
	    v.clear();
        for(i = 0; i < no; i++) {
            gets(buffer);
            sscanf(buffer, "%d:%d %d:%d", &s1, &s2, &e1, &e2);
            v.push_back(*new AP(s1,s2,e1,e2));
        }
        v.push_back(*new AP(10,0,10,0));
        v.push_back(*new AP(18,0,18,0));
        sort(v.begin(), v.end(), compareAP);
        // Resolucion
        it1 = v.begin();
        it2 = it1+1;
        i = v.size()-1;
        while (i--) {
            s1 = (*it1).end; // inicio
            e1 = (*it2).start - s1; // duracion
            if ( (e1 > ans) || (e1 == ans && s1 < ansStart) ) {
                ansStart = s1;
                ans = e1;
            }
            it1++; it2++;
        }
        // Salida
        s1 = (ansStart/60)+10; s2 = ansStart%60;
        e1 = (ans/60);         e2 = ans%60;
        if (ans < 60) {
            printf("Day #%d: the longest nap starts at %.2d:%.2d and will last for %d minutes.\n",
                   dayNo, s1, s2, ans);
        } else {
            printf("Day #%d: the longest nap starts at %.2d:%.2d and will last for %d hours and %d minutes.\n",
                   dayNo, s1, s2, e1, e2);
        }
        dayNo++;
	}

	#ifndef ONLINE_JUDGE
    //fclose(stdout);
    #endif

    return 0;
}
