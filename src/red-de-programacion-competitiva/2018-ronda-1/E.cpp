#include <bits/stdc++.h>
using namespace std;

struct Department {
    Department() {}
    Department(int size) : size(size) {}
    int index, size;
};

bool operator<(const Department& lhs, const Department& rhs) {
    return lhs.size > rhs.size;
}

struct Building {
    int index, size, cost;
};

bool operator<(const Building& lhs, const Building& rhs) {
    if (lhs.cost != rhs.cost) return lhs.cost < rhs.cost;
    return lhs.size > rhs.size;
}

void solve(const vector<Department>& departments, const vector<Building>& buildings) {
    multiset<Department> mset(begin(departments), end(departments));
    
    vector<Building> sorted_buildings(begin(buildings), end(buildings));
    sort(begin(sorted_buildings), end(sorted_buildings));

    vector<int> answer(departments.size());
    for (auto&& b : sorted_buildings) {
        auto department_iterator = mset.lower_bound(Department(b.size));
        if (department_iterator == end(mset)) continue;

        answer[department_iterator->index] = b.index;

        mset.erase(department_iterator);
    }

    if (!mset.empty()) {
        cout << "impossible" << endl;
        return;
    }
    
    for (int i = 0; i < (int)answer.size(); ++i) {
        cout << (i > 0 ? " ": "") << (answer[i] + 1);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    while (cin >> n >> m) {
        vector<Department> departments(n);

        for (int i = 0; i < n; ++i) {
            departments[i].index = i;
            cin >> departments[i].size;
        }

        vector<Building> buildings(m);

        for (int i = 0; i < m; ++i) {
            buildings[i].index = i;
            cin >> buildings[i].size;
        }

        for (int i = 0; i < m; ++i) cin >> buildings[i].cost;

        solve(departments, buildings);
    }
    
    return 0;
}