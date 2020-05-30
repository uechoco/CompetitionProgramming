#include <bits/stdc++.h>
using namespace std;

// ITP1_4_D:   Min, Max and Sum
int main(){
  int n;
  cin >> n;
  std::vector<int64_t> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  // 最小値、最大値、合計値
  int64_t minV = *std::min_element(begin(a), end(a));
  int64_t maxV = *std::max_element(begin(a), end(a));
  int64_t sumV = std::accumulate(begin(a), end(a), 0LL); // long long
  cout << minV << " " << maxV << " " << sumV << endl;
}
