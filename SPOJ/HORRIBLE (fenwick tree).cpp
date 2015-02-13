#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
class RangedFenwickTree
{
public:
  RangedFenwickTree() {}

  RangedFenwickTree(unsigned int n)
  {
    Init(n);
  }

  T Query(int at) const
  {
    T mul = 0, add = 0;
    int start = at;
    while (at >= 0)
    {
      mul += dataMul[at];
      add += dataAdd[at];
      at = (at & (at + 1)) - 1;
    }
    return mul * start + add;
  }

  T QueryInterval(int x, int y) const
  {
    return Query(y) - Query(x-1);
  }

  void Update(int x, int y, T delta)
  {
    InternalUpdate(x, delta, -delta * (x - 1));
    if (y + 1 < (int)this->size())
      InternalUpdate(y + 1, -delta, delta * y);
  }

  unsigned int size() const
  {
    return dataMul.size();
  }

  void Init(unsigned int n)
  {
    dataMul.assign(n, 0);
    dataAdd.assign(n, 0);
  }

  vector<T> dataMul, dataAdd;

private:
  void InternalUpdate(int x, T mul, T add)
  {
    for(int i = x; i < (int)this->size(); i = (i | (i+1)))
    {
      dataMul[i] += mul;
      dataAdd[i] += add;
    }
  }
};

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n, c;
    cin >> n >> c;
    RangedFenwickTree<long long> f(n + 1);
    while (c--)
    {
      int kind, p, q;
      cin >> kind >> p >> q;
      if (kind == 0)
      {
        int value;
        cin >> value;
        f.Update(p, q, value);
      }
      else
      {
        cout << f.QueryInterval(p, q) << endl;
      }
    }
  }
  
  return 0;
}
