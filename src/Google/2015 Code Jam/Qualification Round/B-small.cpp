#include <bits/stdc++.h>
using namespace std;

const int kMaxInitialPlates = 6;
const int kMaxMoves = 6;
typedef array<int, kMaxInitialPlates + kMaxMoves> State;

void uniquify(vector<State> &v)
{
  for(int i = 0; i < (int)v.size(); i++)
  {
    sort(begin(v[i]), end(v[i]));
  }
  sort(begin(v), end(v));
  
  auto new_ending = unique(begin(v), end(v));
  v.resize(distance(begin(v), new_ending));
}

auto get_forward_list(const State &s)
{
  vector<State> f;
  
  for(int src = 0; src < (int)s.size(); src++)
  {
    if (s[src] == 0)
    {
      continue;
    }
    
    for(int dst = 0; dst < (int)s.size(); dst++)
    {
      if (dst == src)
      {
        continue;
      }
      
      for(int cnt = 1; cnt <= s[src]; cnt++)
      {
        State ss = s;
        ss[src] -= cnt;
        ss[dst] += cnt;
        f.push_back(ss);
      }
    }
  }
  
  uniquify(f);
  
  return f;
}

void print_state(const State &s)
{
  cout << "State: (";
  for(int i = 0; i < (int)s.size(); i++)
    cout << (i > 0 ? ", " : "") << s[i];
  cout << ")\n";
}

int solve(const vector<int> &plates)
{
  const int inf = 1000000007;
  int ans = inf;
  
  State initial = {0};
  for(int i = 0; i < (int)plates.size(); i++)
  {
    initial[i] = plates[i];
  }
  
  map<State, int> seen;
  seen[initial] = 0;
  
  queue<State> q;
  q.push(initial);
  
  while (!q.empty())
  {
    State cur = q.front();
    q.pop();
    
    const int moves_done = seen[cur];
    const int max_elem = *max_element(begin(cur), end(cur));
    
    int cand = moves_done + max_elem;
    if (cand < ans)
    {
      //cout << "NEW SOLUTION FOUND\n";
      //cout << "moves_done = " << moves_done << "\n";
      //cout << "associated cost = " << cand << "\n";
      //print_state(cur);
      //cout << "\n";
      
      ans = cand;
    }
    
    if (moves_done >= kMaxMoves)
    {
      continue;
    }
    
    auto fl = get_forward_list(cur);
    
    for(int i = 0; i < (int)fl.size(); i++)
    {
      const State &ss = fl[i];
      if (seen.count(ss) > 0)
      {
        continue;
      }
      
      q.push(ss);
      seen[ss] = moves_done + 1;
    }
  }
  
  return ans;
}

auto read_answers()
{
  FILE *ansf = fopen("last-guess.txt", "r");
  
  int x;
  vector<int> anslist;
  while (fscanf(ansf, "Case #%*d: %d\n", &x) != EOF)
  {
    anslist.push_back(x);
  }
  
  fclose(ansf);
  
  return anslist;
}

int main()
{
  int T;
  cin >> T;
  
  //auto anslist = read_answers();
  
  for(int test = 1; test <= T; test++)
  {
    int D;
    cin >> D;
    
    vector<int> plates;
    for(int i = 0; i < D; i++)
    {
      int x;
      cin >> x;
      plates.push_back(x);
    }
    
    int ans = solve(plates);
    cout << "Case #" << test << ": " << ans << '\n';
    //assert(ans == anslist[test-1]);
  }

  return 0;
}