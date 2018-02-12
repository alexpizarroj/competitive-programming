#include <bits/stdc++.h>
using namespace std;

const map<string, int> colorValue = {
    { "red", 1 },
    { "yellow", 2 },
    { "green", 3 },
    { "brown", 4 },
    { "blue", 5 },
    { "pink", 6 },
    { "black", 7 }
};

int solve(const vector<string>& ballColors) {
    vector<int> values(ballColors.size());
    transform(
        begin(ballColors),
        end(ballColors),
        begin(values),
        [](const string& s) -> int { return colorValue.find(s)->second; }
    );

    int numRedBalls = count_if(begin(values), end(values), [](int x) -> bool { return x == 1; });
    int sumValue = accumulate(begin(values), end(values), 0);
    int maxValue = *max_element(begin(values), end(values));

    if (numRedBalls == (int)values.size()) return 1;
    return (numRedBalls * maxValue) + sumValue;
}

int main() {
    int n;
    while (cin >> n) {
        vector<string> ballColors(n);
        for (auto&& color : ballColors) cin >> color;
        cout << solve(ballColors) << endl;
    }
    return 0;
}