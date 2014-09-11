#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct JOB {
    JOB(int ppos, int ptime, int pfine) : pos(ppos), time(ptime), fine(pfine) {}
    int pos, time, fine;
};

static JOB *jobs[1000];
static int i, j;

bool cmpJOB(JOB *x, JOB *y) {
    i = x->time * y->fine;
    j = y->time * x->fine;
    if (i != j) return i < j;
    return x->pos < y->pos;
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

	int incnt, jobcnt;
	int time, fine;
	bool firstDone = false;

	scanf("%d", &incnt);
	while (incnt--) {
	    scanf("%d", &jobcnt);
        for(i = 0; i < jobcnt; i++) {
            scanf("%d %d", &time, &fine);
            jobs[i] = new JOB(i+1, time, fine);
        }
        sort(jobs, jobs+jobcnt, cmpJOB);
        // Salida
        if(firstDone) cout << endl;
        for(i = 0; i < jobcnt; i++) cout << (i == 0 ? "" : " ") << jobs[i]->pos;
        cout << endl;
        firstDone = true;
	}

    return 0;
}
