#include <iostream>
#include <iomanip>
using namespace std;

const double kNotDone = -1000000.0;
double memo[500][500];

double expected_money(int num_unturned, int num_tries) {
    if (num_tries == 0) return 0;

    if (memo[num_unturned][num_tries] != kNotDone) return memo[num_unturned][num_tries];

    double ans = 0.0;
    if (num_unturned == 0) {    
        ans = 0.5 * (expected_money(1, num_tries - 1) + (-1)) + 0.5 * (expected_money(0, num_tries - 1) + 0);
    } else {
        ans = 0.5 * (expected_money(num_unturned, num_tries - 1) + 0) + 0.5 * (expected_money(num_unturned - 1, num_tries - 1) + 1);
    }

    return memo[num_unturned][num_tries] = ans;
}

void init_memo() {
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 500; ++j) {
            memo[i][j] = kNotDone;
        }
    }
}

int main() {
    init_memo();

    int n, k;
    while (cin >> n >> k) {
        cout << fixed << setprecision(6) << expected_money(n, k) << endl;
    }
    return 0;
}