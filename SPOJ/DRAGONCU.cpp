#include <bits/stdc++.h>
using namespace std;

struct Vector
{
  int x, y;

  Vector() : x(0), y(0) { }

  Vector(int _x, int _y) : x(_x), y(_y) { }

  Vector RotateCCW(int count) const
  {
    Vector res(*this);
    count %= 4;
    while (count--)
    {
      swap(res.x, res.y);
      res.x *= -1;
    }
    return res;
  }
};

Vector operator+(const Vector &lhs, const Vector &rhs)
{
  return Vector(lhs.x + rhs.x, lhs.y + rhs.y);
}

// face = [0..3]; for 0 = East, 1 = North, 2 = West, 3 = South
vector<Vector> precalc, precalc_comp;

Vector Solve(int n, int pos, bool regular_mid)
{
  const int half = (1 << (n - 1)) - 1;

  if (pos <= half)
  {
    return Solve(n - 1, pos, true);
  }
  else if (pos < 2*half + 1)
  {
    Vector left_add = precalc[n - 1];

    Vector mid_add = (regular_mid ? Vector(0, 1) : Vector(0, -1));
    mid_add = mid_add.RotateCCW(1);

    Vector right_add;
    if (pos != half+1)
    {
      int new_face = 1 + (regular_mid ? 1 : -1);
      right_add = Solve(n - 1, pos - half - 1, false).RotateCCW(new_face);
    }

    return left_add + mid_add + right_add;
  }

  return precalc[n];
}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);

  precalc.assign(31, Vector());
  precalc_comp.assign(31, Vector());
  precalc[1] = Vector(0, 1);
  precalc_comp[1] = Vector(0, -1);
  for(int i = 2; i <= 30; i++)
  {
    precalc[i] = precalc[i-1] + precalc[1].RotateCCW(1)
      + precalc_comp[i-1].RotateCCW(2);
    precalc_comp[i] = precalc[i-1] + precalc_comp[1].RotateCCW(1)
      + precalc_comp[i-1];
  }

  int x;
  while (cin >> x, x != -1)
  {
    Vector ans;
    if (x >= 1)
    {
      ans = ans + Vector(1, 0);
    }
    if (x >= 2)
    {
      Vector offset = Solve(30, x - 1, true);
      ans = ans + offset;
    }
    cout << "(" << ans.x << "," << ans.y << ")\n";
  }

  return 0;
}
