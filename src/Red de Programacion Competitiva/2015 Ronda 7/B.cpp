#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
   int TC;
   cin >> TC;
   cin.ignore(1);
    
  while (TC--)
  {
    string s;
    getline(cin, s);
    
    istringstream sst(s);
    vector<string> dic;
    
    string w;
    while (sst >> w) {
     dic.push_back(w);
    }
    
    vector<string> sound;
    while (true)
    {
      string cad;
      getline(cin, cad);
      
      if(cad == "what does the fox say?") break;
      
      int pos = cad.rfind(' ');
      sound.push_back(cad.substr(pos + 1));
    }
    
    int k = 0;
    for (int i = 0; i < (int)dic.size(); ++i)
    {
      if (find(sound.begin(), sound.end(), dic[i]) == sound.end())
      {
         if (k == 0) cout << dic[i];
         else cout << " " << dic[i];
         k++;
      }
    }
    cout << '\n';
  }
    
  return 0;
}
