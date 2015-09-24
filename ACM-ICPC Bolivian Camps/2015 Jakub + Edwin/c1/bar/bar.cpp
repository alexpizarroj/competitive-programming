#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
int values[256] = {0};

struct Node {
  int s, e;       // Interval covered by this node
  int son[2];     // Children of this node
  int val;
};

struct SegmentTree {
  vector<Node> T;

  SegmentTree(int N) {   
    Node n;
    n.s = 0, n.e = N;
    n.son[0] = n.son[1] = -1;
    n.val = -1;

    T.reserve(4 * N);
    T.push_back(n);
    Init(0);
  }

  void Init(int u) {
    Node &n = T[u];
    
    if (n.e - n.s == 1) {
      return;
    }
    
    int mid = (n.s + n.e) / 2;
    for (int i = 0; i < 2; i++) {
      Node c(n);
      if (i == 0)
        c.e = mid;
      else {
        c.son[0] = -1;
        c.s = mid;
      }
      n.son[i] = T.size();
      T.push_back(c);
      Init(n.son[i]);
    }
  }
  
  void Update(int u, int le, int val) {
    Node &n = T[u];
    
    if (n.e <= le || n.s > le) return;

    if (n.s == le && n.e == le + 1) {
      n.val = val;
      return;
    }

    Update(n.son[0], le, val);
    Update(n.son[1], le, val);
    n.val = max(T[n.son[0]].val, T[n.son[1]].val);
  }
  
  int Query(int u, int le, int ri) {
    Node &n = T[u];
    if (n.e <= le || n.s >= ri) return 0;

    if (n.s == le && n.e == ri) return n.val;

    int res = Query(n.son[0], le, min(T[n.son[0]].e, ri));
    res = max(res, Query(n.son[1], max(T[n.son[1]].s, le), ri));
    return res;
  }
};

vector<int> GetMaxGrip(const string& s) {
  const int n = s.size();
  
  set<ii> st;
  vector<int> sum(n);
  
  for(int i = 0; i < n; i++) {
    sum[i] += (i > 0 ? sum[i-1] : 0) + values[(int)s[i]];
    st.insert(make_pair(sum[i], i));
  }
   
  vector<int> result(n);
  for(int i = 0; i < n; i++) {
    int& i_ending = result[i];
    i_ending = -1;
    
    const int bad_value = sum[i] - 2;
    auto it = st.lower_bound(make_pair(bad_value, 0));
    
    if (s[i] == 'p') {
      if (it == st.end()) { // Take the closest 'worst' element
        --it;
        it = st.lower_bound(make_pair(it->first, 0));
        i_ending = it->second - 1;
      } else if (it->first > bad_value) { // We can go 'till the end
        i_ending = n - 1;
      } else { // We can go till the value we just found
        i_ending = it->second - 1;
      }
    }
    
    auto it2 = st.lower_bound(make_pair(sum[i], i));
    st.erase(it2);
    
    assert(i_ending == -1 || i_ending >= i);
  }
  
  return result;
}

int main() {
  values[(int)'p'] = 1;
  values[(int)'j'] = -1;
  
  int n;
  cin >> n;
  
  string s;
  cin >> s;
  
  string s2 = s;
  reverse(begin(s2), end(s2));
  
  auto vec1 = GetMaxGrip(s);
  auto vec2 = GetMaxGrip(s2);
  reverse(begin(vec2), end(vec2));
  for(int& x : vec2) {
    if (x != -1) {
      x =  n - 1 - x;
    }
  } 
  
  int ans = 0;
  
  // Information that we're gonna need to work with the segment tree
  vector<ii> st_final_info;
  for(int j = 0; j < n; j++) {
    int i = vec2[j];
    if (i == -1) {
      continue;
    }
    st_final_info.push_back(make_pair(i, j));
  }
  sort(begin(st_final_info), end(st_final_info), greater<ii>());
  
  vector<ii> st_final_info_2 = st_final_info;
  sort(begin(st_final_info_2), end(st_final_info_2), [](ii a, ii b) {
    return (a.second) < (b.second);
  });
  
  vector<ii> starts;
  for(int i = 0; i < n; i++) {
    int j = vec1[i];
    if (j == -1) {
      continue;
    }
    starts.push_back(make_pair(j, i));
  }
  sort(begin(starts), end(starts));
  
  // Solving for each starting position using a ST
  if ((int)st_final_info.size() > 0) {
    const int m = st_final_info.size();
    SegmentTree st(m);
    int nxj = 0; // Pointer to the next 'j' that should be added
    
    // Using the segment tree, solve it!
    for(int cur = 0; cur < (int)starts.size(); cur++) {
      const int i = starts[cur].second;
      
      while (nxj < m && st_final_info_2[nxj].second <= starts[cur].first) {
        ii target = st_final_info_2[nxj];

        auto it = lower_bound(begin(st_final_info), end(st_final_info), target,
                              greater<ii>());
        int loc = distance(begin(st_final_info), it);
        st.Update(0, loc, target.second);
        
        nxj += 1;
      }
      
      auto it = lower_bound(begin(st_final_info), end(st_final_info),
                            make_pair(i, 10000000007), greater<ii>());
      int pos = distance(begin(st_final_info), it);
      int ret = st.Query(0, pos, m);
      
      if (ret >= i) {
        int j = min(vec1[i], ret);
        if (j - i + 1 > ans) {
          ans = j - i + 1;
        }
      }
    }
  }
  
  cout << ans << '\n';
  
  return 0;
}
