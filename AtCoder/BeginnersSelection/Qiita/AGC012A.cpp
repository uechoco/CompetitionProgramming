#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  std::vector<int64_t> a(3 * n, 0);
  for (int i = 0; i < 3 * n; ++i) {
    cin >> a[i];
  }

  // 先頭から2つずつとっていったときの2つめの値がチームの強さ
  sort(a.begin(), a.end(), std::greater<int64_t>());
  int64_t total = 0;
  for (int i = 0; i < n; ++i) {
    total += a[i * 2 + 1];
  }

  cout << total << endl;
  return 0;
}
