#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const vector<string> kLargeFontArt{
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
  Page() { Clean(); }

  void Print() {
    for (auto&& line : grid_) cout << line << '\n';
    cout << '\n' << string(kColCount, '-') << '\n' << endl;
  }

  void PrintAndClean() {
    Print();
    Clean();
  }

  void Write(const string& text, int row, int col, bool use_large_font) {
    if (!use_large_font) {
      for (int i = 0; i < (int)text.size(); ++i)
        WriteOnGrid(row, col + i, text[i]);
      return;
    }

    for (int i = 0; i < (int)text.size(); ++i) {
      char ch = toupper(text[i]);
      if (ch < 'A' || ch > 'Z') continue;

      const int kFontArtOffset = (ch - 'A') * kLargeFontRowsPerChar;

      for (int j = 0; j < kLargeFontRowsPerChar; ++j) {
        for (int k = 0; k < kLargeFontColsPerChar; ++k) {
          int dst_row = row + j;
          int dst_col = col + i * kLargeFontColsPerChar + k;
          WriteOnGrid(dst_row, dst_col, kLargeFontArt[j + kFontArtOffset][k]);
        }
      }
    }
  }

  void WriteLeftJustified(const string& text, int row, bool use_large_font) {
    int col = 0;
    Write(text, row, col, use_large_font);
  }

  void WriteRightJustified(const string& text, int row, bool use_large_font) {
    int col = kColCount - MeasureTextHorizontally(text, use_large_font);
    Write(text, row, col, use_large_font);
  }

  void WriteCentered(const string& text, int row, bool use_large_font) {
    int text_len = MeasureTextHorizontally(text, use_large_font);

    int col = (kColCount - text_len) / 2;
    if (text_len % 2 == 1) col = ((kColCount + 2) - (text_len + 1)) / 2;

    Write(text, row, col, use_large_font);
  }

  void Clean() { grid_ = vector<string>(kRowCount, string(kColCount, '.')); }

 private:
  const int kRowCount = 60, kColCount = 60;
  const int kLargeFontRowsPerChar = 5, kLargeFontColsPerChar = 6;
  vector<string> grid_;

  void WriteOnGrid(int i, int j, char ch) {
    if (i < 0 || i >= kRowCount) return;
    if (j < 0 || j >= kColCount) return;
    if (ch == '.' || ch == ' ') return;
    grid_[i][j] = ch;
  }

  int MeasureTextHorizontally(const string& text, bool use_large_font) {
    return text.size() * (use_large_font ? kLargeFontColsPerChar : 1);
  }
};

class PageCommand {
 public:
  PageCommand(const string& command_str) {
    if (StartsWith(command_str, ".EOP")) {
      command_type_ = "EOP";

    } else if (StartsWith(command_str, ".P")) {
      auto args = SplitInput(command_str, 5);

      command_type_ = "P";
      use_large_font_ = (args[1][1] == '5');
      row_ = atoi(args[2].c_str()) - 1;
      col_ = atoi(args[3].c_str()) - 1;
      text_ = args[4].substr(1, args[4].size() - 2);

    } else {
      auto args = SplitInput(command_str, 4);

      command_type_ = args[0].substr(1, args[0].size() - 1);
      use_large_font_ = (args[1][1] == '5');
      row_ = atoi(args[2].c_str()) - 1;
      text_ = args[3].substr(1, args[3].size() - 2);
    }
  }

  void Execute(Page& page) {
    if (command_type_ == "EOP")
      page.PrintAndClean();
    else if (command_type_ == "P")
      page.Write(text_, row_, col_, use_large_font_);
    else if (command_type_ == "L")
      page.WriteLeftJustified(text_, row_, use_large_font_);
    else if (command_type_ == "R")
      page.WriteRightJustified(text_, row_, use_large_font_);
    else if (command_type_ == "C")
      page.WriteCentered(text_, row_, use_large_font_);
  }

 private:
  string command_type_, text_;
  bool use_large_font_;
  int row_, col_;

  bool StartsWith(const string& s, const string& prefix) {
    if (s.size() < prefix.size()) return false;

    for (int i = 0; i < (int)prefix.size(); ++i)
      if (s[i] != prefix[i]) return false;

    return true;
  }

  vector<string> SplitInput(const string& input_line, int num_args) {
    vector<string> result;

    istringstream iss(input_line);
    for (int i = 0; i < num_args - 1; ++i) {
      string arg;
      iss >> arg;
      result.push_back(arg);
    }

    string remaining;
    iss.ignore(1);
    getline(iss, remaining);
    result.push_back(remaining);

    return result;
  }
};

int main() {
  string input_line;
  Page page;

  while (getline(cin, input_line)) {
    PageCommand(input_line).Execute(page);
  }

  return 0;
}
