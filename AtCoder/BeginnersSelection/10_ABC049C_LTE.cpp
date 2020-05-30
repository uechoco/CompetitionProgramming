#include <bits/stdc++.h>
using namespace std;

const vector<string> words = {"dream", "dreamer", "erase", "eraser"};

bool match(const string& s, const string& baseT) {
  for (int i = 0; i < 4; ++i) {
    const string newT = baseT + words[i];
    if (s.find(newT) != std::string::npos) {
      if (s.length() == newT.length()) {
        return true;
      } else {
        if (match(s, newT)) {
          return true;
        }
      }
    }
  }
  return false;
}

// ABC049C - 白昼夢
// T の末尾に dream dreamer erase eraser のいずれかを追加する。
// 0, 1, 2, 3
int main(){
  string s, t;
  cin >> s;

  cout << (match(s, t) ? "YES" : "NO") << endl;
  return 0;
}

