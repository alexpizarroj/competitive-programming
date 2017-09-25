#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> CPair;

/*
  Sorts and removes duplicates
*/
template<class T>
void uniquify(T &cont)
{
  sort(begin(cont), end(cont));
  auto it = unique(begin(cont), end(cont));
  cont.erase(it, end(cont));
}

/*
  Returns the cartesian product <occupied cells> * <all cells>
  minus the ones of the form <x> * <x> (product with itself)
*/
vector<CPair> getSpecialBoardPairs(const vector<string> &tt)
{
  const int n = tt.size();
  vector<CPair> table_pairs;

  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
  {
    for(int k = 0; k < n; k++) for(int a = 0; a < n; a++)
    {
      {
        if ((i == k && j == a) || tt[i][j] != 'o')
        {
          continue;
        }

        CPair item = make_pair(ii(i, j), ii(k, a));
        table_pairs.push_back(item);
      }
    }
  }
  
  uniquify(table_pairs);

  return table_pairs;
}

/*
  Set of invalid moves in order to satisfy '.' constraints
*/
vector<ii> getInvalidMoves(const vector<string> &tt, const vector<CPair> &cp)
{
  vector<ii> result;

  for(auto&& item : cp)
  {
    ii a = item.first, b = item.second;

    if (tt[b.first][b.second] == '.')
    {
      ii new_move(b.first - a.first, b.second - a.second);
      result.push_back(new_move);
    }
  }

  uniquify(result);

  return result;
}

/*
  Determines if, using 'imoves' as a list of forbidden moves,
  the situation depicted in the 'tt' board is possible
*/
bool isValidSetup(const vector<string> &tt, const vector<CPair> &cp,
  const vector<ii> &imoves)
{
  const int n = tt.size();
  bool attacked[n][n];
  memset(attacked, 0, sizeof attacked);

  for(auto&& item : cp)
  {
    ii a = item.first, b = item.second;

    if (!attacked[b.first][b.second])
    {
      ii rm(b.first - a.first, b.second - a.second);
      bool is_valid_move = !binary_search(begin(imoves), end(imoves), rm);

      if (is_valid_move)
      {
        attacked[b.first][b.second] = true;
      }
    }
  }

  bool ok = true;
  for(int i = 0; ok && i < n; i++)
  {
    for(int j = 0; ok && j < n; j++)
    {
      bool one = (tt[i][j] == 'x' && !attacked[i][j]);
      bool theOther = (tt[i][j] == '.' && attacked[i][j]);
      if (one || theOther)
      {
        ok = false;
      }
    }
  }

  return ok;
}

/*
  Draws the move matrix based on a set of invalid moves
*/
vector<string> getMoveMatrix(const int n, const vector<ii> &imoves)
{
  const int kSide = (2*n-1);
  vector<string> out(kSide, string(kSide, 'x'));
  
  out[kSide / 2][kSide / 2] = 'o';
  for(auto&& item : imoves)
  {
    out[kSide / 2 + item.first][kSide /2 + item.second] = '.';
  }

  return out;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n)
  {
    vector<string> tt(n, string());
    for(int i = 0; i < n; i++)
    {
      cin >> tt[i];
    }

    auto board_pairs = getSpecialBoardPairs(tt);
    vector<ii> imoves = getInvalidMoves(tt, board_pairs);
    bool ok = isValidSetup(tt, board_pairs, imoves);

    if (ok)
    {
      cout << "YES\n";
      auto moves_matrix = getMoveMatrix(n, imoves);
      for(auto&& row : moves_matrix)
      {
        cout << row << "\n";
      }
    }
    else
    {
      cout << "NO\n";
    }
  }

  return 0;
}