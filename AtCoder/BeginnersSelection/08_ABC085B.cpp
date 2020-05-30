#include <bits/stdc++.h>
using namespace std;

// ABC085B - Kagami Mochi
int main(){
  int n;
  cin >> n;

  vector<int> d(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  std::sort(d.begin(), d.end(), std::greater<int>());
  auto itr = std::unique(d.begin(), d.end());
  d.erase(itr, d.end());

  int cnt = d.size();
  cout << cnt << endl;
  return 0;
}
