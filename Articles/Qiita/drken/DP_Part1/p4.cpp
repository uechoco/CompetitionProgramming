#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000009;

// 問題 4:　部分和数え上げ問題　
int main(){
  int n, A;
  cin >> n;
  vector<int> a(n+10, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> A;

  vector<vector<int>> dp(n+10, vector<int>(A+3, 0));
  // dp[i + 1][j]: i番目までの整数の中で、いくつか選んで総和をjとすることか可能な通り
  //   dp[i][j-a[i]]

  // DP初期条件 dp[0][0] = 1;
  dp[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= A; ++j) {
      dp[i + 1][j] += dp[i][j] % MOD;
      if (j >= a[i]) {
        dp[i + 1][j] += dp[i][j-a[i]] % MOD;
      }
    }
  }

  cout << dp[n][A] << endl;
  return 0;
}
