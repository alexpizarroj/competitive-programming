#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solver {
public:
  void read_testcase() {
    string text;
    
    getline(cin, text);
    assert((int)text.size() == 0);
    
    getline(cin, text);
    vector<string> stops = split(text, 7);
    sort(begin(stops), end(stops));
    m = stops.size();
    
    getline(cin, text);
    vector<string> lines = split(text, 7);
    sort(begin(lines), end(lines));
    n = lines.size();
    
    stop_lines.assign(m, vi());
    line_stops.assign(n, vi());
    int sum = 0;
    
    for (int i = 0; i < n; ++i) {
      getline(cin, text);
      
      vector<string> content = split(text);
      sum += (int)content.size() - 2;
      
      int line_id = index_of(lines, content[0]);
      assert(line_id >= 0 && line_id < n);
      
      for (int j = 2; j < (int)content.size(); ++j) {
        int stop_id = index_of(stops, content[j]);
        assert(stop_id >= 0 && stop_id < m);
        
        stop_lines[stop_id].push_back(line_id);
        line_stops[line_id].push_back(stop_id);
      }
    }
    
    assert(sum <= 1000000);
    
    string src_name, dst_name;
    getline(cin, text);
    src_name = split(text)[3];
    getline(cin, text);
    dst_name = split(text)[3];
    
    src = index_of(stops, src_name);
    assert(src >= 0 && src < m);
    dst = index_of(stops, dst_name);
    assert(dst >= 0 && dst < m);
    
    ans_prefix = "optimal travel from " + src_name + " to " + dst_name + ": ";
  }
  
  void solve() {
    const int kNotSolved = -1;
    vi b(m, kNotSolved), c(m, 0);
    b[src] = c[src] = 0;
    
    vector<bool> line_queued(n,  false);
    vector<int> next_lines = stop_lines[src];
    for (int u : stop_lines[src]) {
      line_queued[u] = true;
    }
    
    for (int a = 0; b[dst] == kNotSolved; a += 1) {
      assert(next_lines.size() > 0);
      
      vector<int> to_do = next_lines;
      next_lines.clear();
      
      for (int line_id : to_do) {
        // Set b[stop_id] and populate 'next_lines'
        for (int stop_id : line_stops[line_id]) {
          if (b[stop_id] != kNotSolved) {
            continue;
          }
          b[stop_id] = a + 1;
          for (int adj_line_id : stop_lines[stop_id]) {
            if (!line_queued[adj_line_id]) {
              next_lines.push_back(adj_line_id);
              line_queued[adj_line_id] = true;
            }
          }
        }
        // Fill c[stop_id] for all stops
        const int len = line_stops[line_id].size();
        int best = -1000000007;
        for (int i = 0; i < len; ++i) {
          const int stop_id = line_stops[line_id][i];
          best += 1;
          if (b[stop_id] == a) {
            best = max(best, c[stop_id]);
          } else {
            c[stop_id] = max(c[stop_id], best);
          }
        }
        best = -1000000007;
        for (int i =  len-1 ; i >= 0; --i) {
          const int stop_id = line_stops[line_id][i];
          best += 1;
          if (b[stop_id] == a) {
            best = max(best, c[stop_id]);
          } else {
            assert(b[stop_id] == a + 1);
            c[stop_id] = max(c[stop_id], best);
          }
        }
      }
    }
    
    show_answer(b[dst], c[dst]);
  }
  
private:
  int m, n; // # stop, # lines
  int src, dst; // starting stop, destination stop
  vector<vi> line_stops, stop_lines;
  string ans_prefix;
  
  vector<string> split(string str, int offset = 0) {
    char* cstr = (char*)str.c_str() + offset;
    vector<string> result;
    
    for(char* pch = strtok(cstr, ", "); pch != NULL; pch = strtok(NULL, ", ")) {
      result.push_back(pch);
    }
    
    return result;
  }
  
  int index_of(const vector<string>& vec, const string& elem) {
    auto it = lower_bound(begin(vec), end(vec), elem);
    int d = distance(begin(vec), it);
    if (*it != elem) {
      d = vec.size();
    }
    return d;
  }
  
  void show_answer(int a, int b) {
    cout << ans_prefix;
    cout << a << " line" << (a == 1 ? "" : "s") << ", ";
    cout << b << " minute" << (b == 1 ? "" : "s") << endl;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int tc;
  cin >> tc;
  cin.ignore(1);
  
  for (int cas = 1; cas <= tc; ++cas) {
    Solver ss;
    ss.read_testcase();
    ss.solve();
  }
  
  return 0;
}
