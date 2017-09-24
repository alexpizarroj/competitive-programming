#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  string nextClosestTime(string time) {
    const int kDayMinutes = 1440;
    
    vector<bool> valid(255, false);
    for (int i = 0; i < (int)time.size(); ++i) {
      valid[(int)time[i]] = true;
    }
    
    int curtime = toValue(time);
    
    while (true) {
      curtime = (curtime + 1) % kDayMinutes;
      string timestr = toString(curtime);
      
      bool good = true;
      for (int i = 0; i < (int)timestr.size(); ++i) {
        if (!valid[(int)timestr[i]]) {
          good = false;
          break;
        }
      }
      if (!good) continue;
      
      return timestr;
    }
    
    return "wat";
  }
  
private:
  int toValue(const string& time) {
    int x, y;
    
    sscanf(time.c_str(), "%d:%d", &x, &y);
    
    return x * 60 + y;
  }
  
  string toString(int timeValue) {
    int h = timeValue / 60, m = timeValue % 60;
    
    char buffer[6]; buffer[5] = 0;
    sprintf(buffer, "%02d:%02d", h, m);
    
    return string(buffer);
  }
};

int main() {
  Solution s;
  cout << s.nextClosestTime("19:34") << endl;
  cout << s.nextClosestTime("23:59") << endl;
  
  return 0;
}
