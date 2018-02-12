#include <bits/stdc++.h>
using namespace std;

struct Planet {
    int daylen, sunrise, sunset;

    bool is_night_time(int hour) const {
        if (sunrise < sunset) {
            return hour <= sunrise || hour >= sunset;
        } else {
            return hour <= sunrise && hour >= sunset;
        }
    }
    
    void set_daytimes_to_false_over_period(vector<bool>& period) const {
        for (int i = 0; i < (int)period.size(); ++i) {
            int hour = i % daylen;
            if (is_night_time(hour)) continue;
            period[i] = false;
        }
    }
};

int max_day_length(const vector<Planet>& planets) {
    int longest = 0;
    for (int i = 0; i < (int)planets.size(); ++i) {
        longest = max(longest, planets[i].daylen);
    }
    return longest;
}

void solve(const vector<Planet>& planets) {
    int max_daylen = max_day_length(planets);
    
    vector<bool> is_night_period(1825 * max_daylen, true);

    for (int i = 0; i < (int)planets.size(); ++i) {
        planets[i].set_daytimes_to_false_over_period(is_night_period);
    }

    for (int i = 0; i < (int)is_night_period.size(); ++i) {
        if (is_night_period[i]) {
            cout << i << endl;
            return;
        }
    }

    cout << "impossible" << endl;
}

int main() {
    int n;
    while (cin >> n) {
        vector<Planet> planets(n);
        for (int i = 0; i < n; ++i) {
            cin >> planets[i].daylen >> planets[i].sunrise >> planets[i].sunset;
        }
        solve(planets);
    }
    return 0;
}