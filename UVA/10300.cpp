#include <stdio.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, i, f, j, total, size, animals, env;

    scanf("%d", &n);
    for(i=0;i<n;i++) {
        total=0;
        scanf("%d", &f);
        for(j=0;j<f;j++) {
            scanf("%d %d %d", &size, &animals, &env);
            total+=size*env;
        }
        printf("%d\n", total);
    }

    //fclose(stdout);
    return 0;
}
