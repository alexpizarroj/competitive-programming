#include <iostream>
#include <map>
#include <cstring>
#include <string>
using namespace std;

struct Node {
  map<char, Node> child;
  int val, sum;
  Node() : val(0), sum(0) {}
};

class MapSum {
public:
    MapSum() {
      
    }
    
    void insert(string key, int val) {
      if (key == "") return;
      const int previousValue = findWordValue(key);
      
      Node* cur = &root;
      cur->sum += val - previousValue;
      
      for (int i = 0; i < (int)key.size(); ++i) {
        // Move next
        const int next = (int)key[i];
        cur = &(cur->child[next]);
        // Update value
        cur->sum += val - previousValue;
      }
      
      // Final touch
      cur->val = val;
    }
    
    int sum(string prefix) {
      return findPrefixNode(prefix).sum;
    }
  
private:
  Node root;
  
  int findWordValue(const string& key) {
    return findPrefixNode(key).val;
  }
  
  Node& findPrefixNode(const string& key) {
    Node* cur = &root;
    
    for (int i = 0; i < (int)key.size(); ++i) {
      const int next = (int)key[i];
      cur = &(cur->child[next]);
    }
    
    return *cur;
  }
};

int main() {
  MapSum mp;
  mp.insert("apple", 3);
  cout << mp.sum("ap") << endl;;
  mp.insert("app", 2);
  cout << mp.sum("ap") << endl;
  
  cout << "Extra" << endl;
  cout << mp.sum("") << endl;
  cout << mp.sum("a") << endl;
  cout << mp.sum("ap") << endl;
  cout << mp.sum("app") << endl;
  cout << mp.sum("appl") << endl;
  cout << mp.sum("apple") << endl;
  
  return 0;
}
