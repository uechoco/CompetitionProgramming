
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
// syntax sugar: `for (int i = 0; i < N; ++i)`
#define REP(type, name, beginValue, endCondValue) \
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


// ナップサック問題
int main(){
  int n, W;
  cin >> n >> W;
  vector<int> weight(n, 0);
  vector<int> value(n, 0);
  rep(i, n) {
    cin >> weight[i] >> value[i];
  }

  VECTOR_DIM2(int, dp, n+10,W+10,0);
  rep(w,W+1){
    dp[0][w] = 0;
  }
  rep(i,n) {
    rep(w,W+1) {
      if (w >= weight[i]) {
        dp[i+1][w] = max(dp[i][w-weight[i]]+value[i], dp[i][w]);
      } else {
        dp[i+1][w] = dp[i][w];
      }
    }
  }

  cout << dp[n][W] << endl;

  return 0;
}

/*
N=6 W=9 // ans = 94

6 9
2 3 1 2 3 6 2 1 1 3 5 85
*/
