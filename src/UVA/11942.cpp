#include <stdio.h>

using namespace std;


bool fromLower(int a, int b) { return a < b; }
bool fromHigher(int a, int b) { return a > b; }

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n, a, b, i;
    bool (*cmp) (int, int);
    bool ordered;

    printf("Lumberjacks:\n");
    scanf("%d", &n);
    while (n--) {
        // Resolucion
        scanf("%d", &a);
        scanf("%d", &b);
        cmp = (a > b ? fromHigher : fromLower);
        ordered = true; a = b;
        i = 8; while (i--) {
            scanf("%d", &b);
            if (!cmp(a, b)) {
                ordered = false;
                while (i--) scanf("%d", &b);
                break;
            }
            a = b;
        }
        // Salida
        printf(ordered ? "Ordered\n" : "Unordered\n");
    }

    return 0;
}
