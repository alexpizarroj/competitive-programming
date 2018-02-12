#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& settings, int height) {
    int best_idx = 0;
    for (int i = 0; i < (int)settings.size(); ++i) {
        int current = height % settings[best_idx];
        int candidate = height % settings[i];
        if (candidate < current) best_idx = i;
    }
    return settings[best_idx];
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> settings(n);
        for (auto&& x : settings) cin >> x;

        int height;
        cin >> height;

        cout << solve(settings, height) << endl;
    }
    return 0;
}