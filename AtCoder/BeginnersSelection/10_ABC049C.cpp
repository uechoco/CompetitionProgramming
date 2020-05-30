#include <bits/stdc++.h>
using namespace std;

const vector<string> words = {"dream", "dreamer", "erase", "eraser"};

bool match(const string& s, const std::size_t pos) {
  const size_t sLen = s.length();
  for (int i = 0; i < 4; ++i) {
    if (s.find(words[i], pos) == pos) {
      if (sLen == pos + words[i].length()) {
        return true;
      } else {
        if (match(s, pos + words[i].length())) {
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

  cout << (match(s, 0) ? "YES" : "NO") << endl;
  return 0;
}

