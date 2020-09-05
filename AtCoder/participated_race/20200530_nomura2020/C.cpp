#include <bits/stdc++.h>
using namespace std;

// C
int main(){
  // GIVE UP
  int n;
  cin >> n; // 0 ~ 100000
  vector<int64_t> a(n+1, 0);
  for (int i = 0; i < n+1; ++i) {
    cin >> a[i]; // 0 ~ 100000000
  }

  // 深さの数が現実的に構築可能な頂点数以上を要求されている場合はNG
  {
    for (int i = 0; i < n+1; ++i) {
      int dMax = 1 << i;
      if (dMax > 100000000) {
        break;
      }
      if (a[i] > dMax) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
  return 0;
}
