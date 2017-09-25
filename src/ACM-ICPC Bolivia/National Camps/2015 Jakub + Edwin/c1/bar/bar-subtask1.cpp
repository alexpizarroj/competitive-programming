#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
int values[256] = {0};

vector<int> f(const string& s) {
  const int n = s.size();
  
  set<ii> st;
  vector<int> sum(n);
  for(int i = 0; i < n; i++) {
    sum[i] += (i > 0 ? sum[i-1] : 0) + values[(int)s[i]];
    st.insert(make_pair(sum[i], i));
  }
 
 /* 
  int var = 0;
  for(int i = 0; i < n; i++) {
    ii target(-1 + var, 0);
    auto it = st.lower_bound(target);
    
    if (it == st.end()) {
      // We have a guaranteed end
      --it;
      
    } else {
      //
    }
    
    // Update for the next iteration
    auto it2 = st.lower_bound(make_pair(sum[i], i));
    st.erase(it2;)
    var -= values[(int)s[i]];
  }*/
    
    return vector<int>();
}

int main() {
  values[(int)'p'] = 1;
  values[(int)'j'] = -1;
  
  int n;
  cin >> n;
  
  string s;
  cin >> s;
  
  string ss = s;
  reverse(begin(ss), end(ss));
  
  
  
  
  return 0;
}
