#include <bits/stdc++.h>
using namespace std;

const int64_t MAX_ANS = 1000000000000000000;

int main(){
  int n;
  cin >> n;
  vector<int64_t> a(n, 0);
  bool hasZero = false;
  for (int i =0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 0) {
      hasZero = true;
    }
  }
  if (hasZero) {
      cout << 0 << endl;
      return 0;
  }

  int64_t total = 1;
  for (int i =0; i < n; ++i) {
    if (MAX_ANS / total < a[i]) {
      cout << "-1" << endl;
      return 0;
    }
    total *= a[i];
  }

  cout << total << endl;
  return 0;
}
