#include <bits/stdc++.h>
using namespace std;

// 問題 1:　最大和問題
int main(){
  int n;
  cin >> n;
  vector<int> a(n+10, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> dp(n+10, 0);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = max(dp[i], dp[i] + a[i]);
  }

  cout << (dp[n]) << endl;
  return 0;
}
