#include <bits/stdc++.h>
using namespace std;

// 問題 3:　部分和問題
int main(){
  int n, A;
  cin >> n;
  vector<int> a(n+10, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> A;

  vector<vector<bool>> dp(n+10, vector<bool>(A+3, false));
  // dp[i + 1][j]: i番目までの整数の中で、いくつか選んで総和をjとすることか可能かどうか
  //   dp[i][j-a[i]] が true: true

  // DP初期条件 dp[0][j] = ;
  dp[0][0] = true;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= A; ++j) {
      dp[i + 1][j] = dp[i + 1][j] | dp[i][j];
      if (j >= a[i]) {
        dp[i + 1][j] = dp[i + 1][j] | dp[i][j-a[i]];
      }
    }
  }

  cout << (dp[n][A] ? "YES" : "NO") << endl;
  return 0;
}
