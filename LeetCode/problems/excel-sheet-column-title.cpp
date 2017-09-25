// https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
  string convertToTitle(int n) {
    int len = 1;
    long long space = alphasize;
    n -= 1;

    while (n >= space) {
      len += 1;
      n -= space;
      space *= alphasize;
    }

    return convertToFixedSizeTitle(n, len);
  }
private:
  const int alphasize = ('Z' - 'A' + 1);

  string convertToFixedSizeTitle(int n, int len) {
    string result = "";

    do {
      result.push_back((n % alphasize) + 'A');
      n /= alphasize;
    } while (n > 0);

    while ((int)result.size() < len) {
      result.push_back('A');
    }

    reverse(begin(result), end(result));

    return result;
  }
};
