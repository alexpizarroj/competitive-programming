#include <iostream>
#include <cstdio>
#define MAX 100001

using namespace std;
struct Soldier { int prev, next; };
Soldier v[MAX];


int main() {
    //freopen("army.mine.in", "r", stdin);
    //freopen("army.in", "r", stdin); freopen("army.mine.out", "w", stdout);

    int s, b, l, r, lb, rb;
    int i;

    while ( scanf("%d %d", &s, &b) != EOF ) {

		if( s == 0 ) break;

        for(i=1; i<=s; i++) {
            v[i].prev = i-1;
            v[i].next = i+1;
        }
        v[s].next = 0;

        while ( b-- ) {
            scanf("%d %d", &l, &r);

            lb = v[l].prev;
            rb = v[r].next;
            v[lb].next = rb;
            v[rb].prev = lb;

            if( lb ) printf("%d", lb); else printf("*");
            printf(" ");

            if( rb ) printf("%d", rb); else printf("*");
            printf("\n");
        }

        printf("-\n");

    }

    return 0;
}
