
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


// 部分わ問題
int main(){
  int n, A;
  cin >> n >> A;
  vector<int> a(n, 0);
  rep(i, n) {
    cin >> a[i];
  }

  // dp[i+1][j]: i番目の整数まででいくつか選んで総和をjとすることが可能か
  VECTOR_DIM2(bool, dp, n+10, A+10, false);
  dp[0][0] = true; // 初期条件

  rep(i,n){
    rep(j,A+1) {
      dp[i+1][j] = dp[i+1][j] | dp[i][j];
      if (j >= a[i]) {
        dp[i+1][j] = dp[i+1][j] | dp[i][j-a[i]];
      }
    }
  }


  cout << (dp[n][A] ? "YES" : "NO") << endl;

  return 0;
}

/*
n=3, A=10, a=7,5,3 // ans=YES
3 10 7 5 3

n=2 A=6 a=9,7 // ans=NO
2 6 9 7
*/
