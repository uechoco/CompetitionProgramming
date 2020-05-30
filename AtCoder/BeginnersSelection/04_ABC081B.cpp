#include <bits/stdc++.h>
using namespace std;

// ABC081B - Shift only
int main(){
  int n;
  cin >> n;
  std::vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int cnt = 0;
  bool succeeded = true;
  do {
    succeeded = true;
    for (int i = 0; i < n; ++i) {
      if (a[i] % 2 == 1) {
        succeeded = false;
        break;
      }
      a[i] /= 2;
    }
    if (succeeded) {
      ++cnt;
    }
  } while(succeeded);
  cout << cnt << endl;
  return 0;
}
