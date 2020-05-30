#include <bits/stdc++.h>
using namespace std;

// ITP1_8_C:   Counting Characters
int main(){
  char ch;
  std::vector<int> nums(26, 0);
  while (cin >> ch) {
    if ('a' <= ch && ch <= 'z') {
      nums[(ch - 'a')]++;
    } else if ('A' <= ch && ch <= 'Z') {
      nums[(ch - 'A')]++;
    }
  }
  for (int i = 0; i < 26; ++i) {
    cout << char('a' + i) << " : " << nums[i] << endl;
  }

  return 0;
}
