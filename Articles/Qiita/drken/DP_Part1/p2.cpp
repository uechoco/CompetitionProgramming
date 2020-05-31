#include <bits/stdc++.h>
using namespace std;

// 問題 2:　ナップサック問題
int main(){
  int n, W;
  cin >> n;
  vector<int> weight(n+10, 0);
  vector<int> value(n+10, 0);
  for (int i = 0; i < n; ++i) {
    cin >> weight[i] >> value[i];
  }
  cin >> W;

  // dp[i + 1][w]: i番目までの品物の中から重さがwを超えないように選んだときの価値の総和の最大値
  // dp[i][w] を選ぶ: w >= weight[i]
  //   dp[i + 1][w] = dp[i][w - weight[i]] + value[i];
  // dp[i][w] を選ばない:
  //   dp[i + 1][w] = dp[i][w]

  // DP初期条件 dp[0][w] = 0
  vector<vector<int>> dp(n+10, vector<int>(W+3, 0));
  for (int w = 0; w <= W; ++w) {
    dp[0][w] = 0;
  }
  // dpループ
  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (w >= weight[i]) {
        dp[i + 1][w] = max(dp[i][w], dp[i][w - weight[i]] + value[i]);
      } else {
        dp[i + 1][w] = dp[i][w];
      }
    }
  }

  cout << (dp[n][W]) << endl;
  return 0;
}
