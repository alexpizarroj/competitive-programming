#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const vector<string> c5FontArt{
    ".***..", "*...*.", "*****.", "*...*.", "*...*.", "****..", "*...*.",
    "****..", "*...*.", "****..", ".****.", "*...*.", "*.....", "*.....",
    ".****.", "****..", "*...*.", "*...*.", "*...*.", "****..", "*****.",
    "*.....", "***...", "*.....", "*****.", "*****.", "*.....", "***...",
    "*.....", "*.....", ".****.", "*.....", "*..**.", "*...*.", ".***..",
    "*...*.", "*...*.", "*****.", "*...*.", "*...*.", "*****.", "..*...",
    "..*...", "..*...", "*****.", "..***.", "...*..", "...*..", "*..*..",
    ".**...", "*...*.", "*..*..", "***...", "*..*..", "*...*.", "*.....",
    "*.....", "*.....", "*.....", "*****.", "*...*.", "**.**.", "*.*.*.",
    "*...*.", "*...*.", "*...*.", "**..*.", "*.*.*.", "*..**.", "*...*.",
    ".***..", "*...*.", "*...*.", "*...*.", ".***..", "****..", "*...*.",
    "****..", "*.....", "*.....", ".***..", "*...*.", "*...*.", "*..**.",
    ".****.", "****..", "*...*.", "****..", "*..*..", "*...*.", ".****.",
    "*.....", ".***..", "....*.", "****..", "*****.", "*.*.*.", "..*...",
    "..*...", ".***..", "*...*.", "*...*.", "*...*.", "*...*.", ".***..",
    "*...*.", "*...*.", ".*.*..", ".*.*..", "..*...", "*...*.", "*...*.",
    "*.*.*.", "**.**.", "*...*.", "*...*.", ".*.*..", "..*...", ".*.*..",
    "*...*.", "*...*.", ".*.*..", "..*...", "..*...", "..*...", "*****.",
    "...*..", "..*...", ".*....", "*****."};

class Page {
 public:
  Page() { clean(); }

  void print() {
    for (auto&& line : grid) cout << line << '\n';
    cout << '\n' << string(kColCount, '-') << '\n' << endl;
    clean();
  }

  void write(const string& text, int row, int col, bool useLargeFont) {
    if (!useLargeFont) {
      for (int i = 0; i < (int)text.size(); ++i) {
        writeOnGrid(row, col + i, text[i]);
      }
      return;
    }

    for (int i = 0; i < (int)text.size(); ++i) {
      char ch = toupper(text[i]);
      if (ch < 'A' || ch > 'Z') continue;

      const int kFontArtOffset = (ch - 'A') * kLargeFontRowsPerChar;

      for (int j = 0; j < kLargeFontRowsPerChar; ++j) {
        for (int k = 0; k < kLargeFontColsPerChar; ++k) {
          int dstRow = row + j;
          int dstCol = col + i * kLargeFontColsPerChar + k;
          writeOnGrid(dstRow, dstCol, c5FontArt[j + kFontArtOffset][k]);
        }
      }
    }
  }

  void writeLeftJustified(const string& text, int row, bool useLargeFont) {
    int col = 0;
    write(text, row, col, useLargeFont);
  }

  void writeRightJustified(const string& text, int row, bool useLargeFont) {
    int col = kColCount - measureTextHorizontally(text, useLargeFont);
    write(text, row, col, useLargeFont);
  }

  void writeCentered(const string& text, int row, bool useLargeFont) {
    int hlen = measureTextHorizontally(text, useLargeFont);

    int col = (kColCount - hlen) / 2;
    if (hlen % 2 == 1) col = ((kColCount + 2) - (hlen + 1)) / 2;

    write(text, row, col, useLargeFont);
  }

  void clean() { grid = vector<string>(kRowCount, string(kColCount, '.')); }

 private:
  const int kRowCount = 60, kColCount = 60;
  const int kLargeFontRowsPerChar = 5, kLargeFontColsPerChar = 6;
  vector<string> grid;

  void writeOnGrid(int i, int j, char ch) {
    if (i < 0 || i >= kRowCount) return;
    if (j < 0 || j >= kColCount) return;
    if (ch == '.' || ch == ' ') return;
    grid[i][j] = ch;
  }

  int measureTextHorizontally(const string& text, bool useLargeFont) {
    return text.size() * (useLargeFont ? kLargeFontColsPerChar : 1);
  }
};

bool startsWith(const string& s, const string& prefix) {
  if (s.size() < prefix.size()) return false;
  for (int i = 0; i < (int)prefix.size(); ++i)
    if (s[i] != prefix[i]) return false;
  return true;
}

vector<string> splitInput(const string& inputLine, int nArgs) {
  vector<string> result;

  istringstream iss(inputLine);
  for (int i = 0; i < nArgs - 1; ++i) {
    string arg;
    iss >> arg;
    result.push_back(arg);
  }

  iss.ignore(1);
  string remaining;
  getline(iss, remaining);
  result.push_back(remaining);

  return result;
}

int main() {
  string inputLine;
  Page p;

  while (getline(cin, inputLine)) {
    if (startsWith(inputLine, ".EOP")) {
      p.print();

    } else if (startsWith(inputLine, ".P")) {
      auto args = splitInput(inputLine, 5);

      bool useLargeFont = (args[1][1] == '5');
      int row = atoi(args[2].c_str()) - 1;
      int col = atoi(args[3].c_str()) - 1;
      string text = args[4].substr(1, args[4].size() - 2);

      p.write(text, row, col, useLargeFont);

    } else {
      auto args = splitInput(inputLine, 4);

      bool useLargeFont = (args[1][1] == '5');
      int row = atoi(args[2].c_str()) - 1;
      string text = args[3].substr(1, args[3].size() - 2);

      if (startsWith(inputLine, ".L"))
        p.writeLeftJustified(text, row, useLargeFont);
      else if (startsWith(inputLine, ".R"))
        p.writeRightJustified(text, row, useLargeFont);
      else if (startsWith(inputLine, ".C"))
        p.writeCentered(text, row, useLargeFont);
    }
  }

  return 0;
}
