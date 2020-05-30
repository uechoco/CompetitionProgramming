#include <bits/stdc++.h>
using namespace std;

// ABC086C - Traveling
int main(){
  int n;
  cin >> n;
  int ct = 0, cx = 0, cy = 0; // 現在時刻、地点
  bool can = true;
  for (int i = 0; i < n; ++i) {
    int t, x, y;
    cin >> t >> x >> y; // 目標時刻、目標地点
    int diffT = t - ct;
    int diffD = std::abs(x - cx) + std::abs(y - cy);
    if (can && diffT >= diffD && (diffT % 2 == diffD % 2)) {
      can = true;
      ct = t; cx = x; cy = y;
    } else {
      can = false;
    }
  }

  cout << (can ? "Yes" : "No") << endl;
  return 0;
}
