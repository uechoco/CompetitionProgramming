
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
// syntax sugar: `for (int i = start; i < N; ++i)`
#define REP(i, start, N) for (int i = start; i < (int)(N); ++i)

#define REP_T(type, name, beginValue, endCondValue) \
  for (type name = beginValue; name < endCondValue; ++name)
// syntax sugar: 多次元vector
#define VECTOR_DIM3(T, name, d1, d2, d3, initValue) \
    std::vector<std::vector<std::vector<T>>> name(d1, std::vector<std::vector<T>>(d2, std::vector<int>(d3, initValue)));
#define VECTOR_DIM2(T, name, d1, d2, initValue) \
    std::vector<std::vector<T>> name(d1, std::vector<T>(d2, initValue));
#define VECTOR_DIM1(T, name, d1, initValue) \
    std::vector<T> name(d1, initValue);
#define ll long long
#define ld long double

// 最小個数部分和問題
int main(){
  int n, A;
  cin >> n >> A;
  vector<int> a(n, 0);
  rep(i, n) {
    cin >> a[i];
  }

  // dp[i+1][j]: i番目までの整数の中からいくつか選んで総和をjとする場合の、選んだ整数の個数の最小値
  VECTOR_DIM2(ll, dp, n+10, A+10, INT_MAX);
  // 初期条件
  dp[0][0] = 0;

  rep(i,n) {
    rep(j, A+1) {
      dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
      if (j >= a[i]) {
        dp[i+1][j] = min(dp[i+1][j],dp[i][j-a[i]] + 1);
      }
    }
  }

  cout << (dp[n][A] < INT_MAX ? dp[n][A] : -1) << endl;

  return 0;
}

/*
n=5, A=12, a=7,5,3,1,8 // ans=2
5 12 7 5 3 1 8

n=2 A=6 a=7,5 // ans=-1
2 6 7 5
*/
