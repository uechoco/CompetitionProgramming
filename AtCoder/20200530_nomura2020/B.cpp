#include <bits/stdc++.h>
using namespace std;

// B
int main(){
  string s;
  cin >> s;

  int sLen = s.length();
  int n = 0;
  for (int i = 0; i < sLen; i++) {
    if (s[i] == '?') {
      if (i > 0 && s[i-1] == 'P') {
        s[i] = 'D';
        continue;
      }
      if (i + 1 < sLen) {
        if (s[i + 1] == 'D') {
          s[i] = 'P';
          continue;
        } else if (s[i + 1] == '?') {
          s[i] = 'P';
          continue;
        }
      }
      s[i] = 'D';
      continue;
    }
  }

  cout << s << endl;
  return 0;
}
