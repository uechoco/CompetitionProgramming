#include <bits/stdc++.h>
using namespace std;

// ABC071B - Not Found
int main(){
  string s;
  cin >> s;

  char bucket[26] = {0};
  std::for_each(s.begin(), s.end(), [&bucket](char c){
    ++bucket[c - 'a'];
  });
  for (int i = 0; i < 26; ++i) {
    if (bucket[i] == 0) {
      cout << char('a' + i) << endl;
      return 0;
    }
  }

  cout << "None" << endl;
  return 0;
}
