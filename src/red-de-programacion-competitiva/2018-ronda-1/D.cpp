#include <bits/stdc++.h>
using namespace std;

using Answer = vector<pair<int, int>>;

Answer solve_from_unsorted_to_sorted(const string& unsorted, const string& sorted) {
    Answer ans;

    string current = unsorted;
    int next_pos = 0;
    for (char curchar = 'a'; curchar <= 'z'; ++curchar) {
        for (int i = 0; i < (int)current.size(); ++i) {
            if (current[i] != curchar) continue;

            if (i == next_pos) {
                next_pos += 1;
                continue;
            }

            swap(current[next_pos], current[i]);
            ans.push_back(make_pair(next_pos + 1, i + 1));
            next_pos += 1;
        }
    }

    return ans;
}

void solve(const string& unsorted) {
    string sorted = unsorted;
    sort(begin(sorted), end(sorted));

    auto ans = solve_from_unsorted_to_sorted(unsorted, sorted);

    for (int i = (int)ans.size() - 1; i >= 0; --i) {
        cout << ans[i].second << " " << ans[i].first << '\n';
    }
}

int main() {
    string input;
    while (cin >> input) solve(input);
    return 0;
}