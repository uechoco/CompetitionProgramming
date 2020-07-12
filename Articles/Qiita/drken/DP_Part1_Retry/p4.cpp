
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

#define MOD 1000000009

// 部分和数え上げ問題
int main(){
  int n, A;
  cin >> n >> A;
  vector<int> a(n, 0);
  rep(i, n) {
    cin >> a[i];
  }

  // dp[i+1][j]: i番目までの整数の中からいくつか選んで総和をjとする場合の数
  VECTOR_DIM2(ll, dp, n+10, A+10, 0);

  // 初期条件
  rep(j,n) {
    dp[0][j] = 0;
  }
  dp[0][0] = 1;

  rep(i,n) {
    rep(j, A+1) {
      dp[i+1][j] += dp[i][j] % MOD;
      if (j >= a[i]) {
        dp[i+1][j] += dp[i][j-a[i]] % MOD;
      }
    }
  }

  cout << dp[n][A] << endl;

  return 0;
}

/*
n=5, A=12, a=7,5,3,1,8 // ans=12
5 12 7 5 3 1 8

n=4 A=5 a=4,1,1,1 // ans=5
4 5 4 1 1 1
*/
