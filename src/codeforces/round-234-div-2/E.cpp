#include <bits\stdc++.h>
using namespace std;

long long GetS(int n)
{
  return (long long)n * (n + 1) / 2;
}

long long GetS(pair<int, int> e)
{
  return GetS(e.second - e.first + 1);
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  // Bit positional value
  const int kBits = 17;
  vector<int> pos_value(kBits);
  pos_value[0] = 1;
  for(int i = 1; i < kBits; i++)
    pos_value[i] = pos_value[i-1] * 2;
  
  typedef pair<int, int> ii;
  int n, m;
  while (cin >> n >> m)
  {
    vector< vector<bool> > seq(kBits, vector<bool>(n));
    for(int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      for(int j = 0; j < kBits; j++)
        seq[j][i] = ((x >> j) & 1);
    }

    vector<long long> sum(kBits, 0);
    vector< set<ii> > intervals(kBits, set<ii>());
    for(int i = 0; i < kBits; i++)
    {
      int len = 0, start = 0;
      for(int j = 0; j <= n; j++)
      {
        if (j < n && seq[i][j] == 1)
        {
          if (len == 0)
            start = j;
          len += 1;
        }
        else if (len > 0)
        {
          intervals[i].insert(make_pair(start, j - 1));
          sum[i] += GetS(len);
          len = 0;
        }
      }
    }

    // Query processing
    while (m--)
    {
      int p, v;
      cin >> p >> v;
      p -= 1;

      for(int i = 0; i < kBits; i++)
      {
        const int value = ((v >> i) & 1);
        if (seq[i][p] == value)
          continue;
        seq[i][p] = value;

        set<ii> &st = intervals[i];
        auto it = st.lower_bound(make_pair(p, p));
        // ------
        // ADDING
        // ------
        if (value == 1)
        {
          // 'it' points to the first interval situated after 'p'

          bool merged_two = false;
          if (it != st.end() && it != st.begin())
          {
            auto it0 = it;
            --it0;
            // Two intervals are merging into only one
            if (it0->second + 2 == it->first)
            {
              merged_two = true;
              ii e(it0->first, it->second);

              sum[i] -= GetS(*it0);
              st.erase(it0);

              sum[i] -= GetS(*it);
              st.erase(it);

              st.insert(e);
              sum[i] += GetS(e);
            }
          }

          bool added = false;
          if (!merged_two)
          {
            // New larger interval of the form X111...
            if (it != st.end() && p + 1 == it->first)
            {
              added = true;
              ii e(p, it->second);
              st.erase(it);
              sum[i] -= GetS(*it);
              st.insert(e);
              sum[i] += GetS(e);
            }
            // New larger interval of the form ...111X
            if (!added && it != st.begin())
            {
              auto it0 = it;
              --it0;
              if (it0->second + 1 == p)
              {
                added = true;
                ii e(it0->first, p);
                st.erase(it0);
                sum[i] -= GetS(*it0);
                st.insert(e);
                sum[i] += GetS(e);
              }
            }
          }

          // A new single interval
          if (!merged_two && !added)
          {
            st.insert(make_pair(p, p));
            sum[i] += 1;
          }
        }
        // --------
        // DELETING
        // --------
        else
        {
          if (it == st.end() || !(it->first <= p && p <= it->second))
            --it;
          // 'it' points to the interval that contains the bit

          ii e = *it;
          st.erase(it);
          sum[i] -= GetS(e);
          if (e.first == p || e.second == p)
          {
            if (e.first < e.second)
            {
              if (e.first == p)
                e.first += 1;
              else
                e.second -= 1;
              st.insert(e);
              sum[i] += GetS(e);
            }
          }
          else
          {
            ii e1(e.first, p - 1), e2(p + 1, e.second);
            st.insert(e1);
            sum[i] += GetS(e1);
            st.insert(e2);
            sum[i] += GetS(e2);
          }
        }
      }

      long long ans = 0;
      for(int i = 0; i < kBits; i++)
      {
        ans += sum[i] * pos_value[i];
        //for(ii e : intervals[i])
        //  cout << "(" << e.first << ", " << e.second << ") ";
        //cout << endl;
      }
      cout << ans << endl;

    }
  }
  
  return 0;
}
