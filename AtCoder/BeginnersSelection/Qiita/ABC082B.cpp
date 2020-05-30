#include <bits/stdc++.h>
using namespace std;

// ABC082B - Two Anagrams
int main(){
  string s, t;
  cin >> s >> t;

  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end(), std::greater<char>());

  int len = (int)min(s.length(), t.length());
  for (int i = 0; i < len; ++i) {
    if (s[i] < t[i]) {
      cout << "Yes" << endl;
      return 0;
    } else if (s[i] > t[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (s.length() < t.length()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
