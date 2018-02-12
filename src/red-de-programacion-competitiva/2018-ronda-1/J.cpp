#include <iostream>
#include <iomanip>
using namespace std;

int code_value[32];

void init_code_values() {
    code_value[16] = 1;
    code_value[8] = 2;
    code_value[4] = 4;
    code_value[2] = 8;
    code_value[1] = 16;
    code_value[0] = 32;
}

double solve(int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int code;
        cin >> code;

        sum += code_value[code];
    }

    return (double)sum / 16;
}

int main() {
    init_code_values();

    int n;
    while (cin >> n) {
        cout << fixed << setprecision(7) << solve(n) << endl;
    }

    return 0;
}