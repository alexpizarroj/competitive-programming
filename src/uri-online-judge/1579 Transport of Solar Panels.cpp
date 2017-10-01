#include <bits/stdc++.h>
using namespace std;

bool pred(int cap, const vector<int>& panels, int n_trucks) {
	int cur = 0, cur_we = 0;
	for(int i = 0; i < (int)panels.size(); i++) {
		if (cur_we + panels[i] <= cap) {
			cur_we += panels[i];
		} else {
			cur_we = panels[i];
			cur += 1;
		}
	}
	return (cur < n_trucks);
}

int main() {
  	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);

  	int tc;
  	cin >> tc;
  	while (tc--) {
  		int m, n, f;
  		cin >> m >> n >> f;

  		vector<int> panels(m);
  		for(int i = 0; i < m; i++) {
  			cin >> panels[i];
  		}

  		int lo = *max_element(panels.begin(), panels.end());
  		int hi = accumulate(panels.begin(), panels.end(), 0);
  		while (lo < hi) {
  			int mid = lo + (hi - lo) / 2;
  			if (pred(mid, panels, n)) {
  				hi = mid;
  			} else {
  				lo = mid + 1;
  			}
  		}

  		int cost = lo * n * f;
  		cout << lo << " $" << cost << '\n';
  	}

  	return 0;
}

