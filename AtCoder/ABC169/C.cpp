#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t a;
  string b;
  cin >> a >> b;
  if (a == 0) {
    cout << 0 << endl;
    return 0;
  }

  bool afterFix = false;
  int badj = 0;
  int afterDiv = 1;
  for (int i = 0; i < (int)b.length(); ++i) {
    if (b[i] == '.') {
      afterFix = true;
      continue;
    }
    if (afterFix) {
      afterDiv *= 10;
    }
    badj = badj * 10 + (b[i] - '0');
  }
  cout << (a * badj) / afterDiv << endl;

  return 0;
}
