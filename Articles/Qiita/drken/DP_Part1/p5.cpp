#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 29; // INT_MAXにしないのは、オーバーフロー対策

// 問題 5:　最小個数部分和問題
int main(){
  int n, A;
  cin >> n;
  vector<int> a(n+10, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> A;

  vector<vector<int>> dp(n+10, vector<int>(A+3, INF));
  // dp[i + 1][j]: i番目までの整数の中で、いくつか選んで総和をjとすることか可能なすべての組み合わせのうち、選んだ整数の個数の最小値
  //   j >= a[i] のとき、a[i]を選ぶ場合、dp[i][j-a[i]]+1

  // DP初期条件 dp[0][0] = 0;
  // DP初期条件 dp[0][j] = INF; // j != 0
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= A; ++j) {
      dp[i + 1][j] = min(dp[i+1][j], dp[i][j]);
      if (j >= a[i]) {
        dp[i + 1][j] = min(dp[i+1][j], dp[i][j-a[i]] + 1);
      }
    }
  }

  if (dp[n][A] < INF) {
    cout << dp[n][A] << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
