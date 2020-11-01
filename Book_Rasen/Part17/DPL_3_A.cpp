#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
#define rep2(i, startValue, N) for (int i = (int)(startValue); i < (int)(N); ++i)
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
#define DUMP(v) "," #v ":" << v

int main(){
  int h, w;
  cin >> h >> w;

  VECTOR_DIM2(int, M, h, w, 0);
  VECTOR_DIM2(int, dp, h, w, 0);
  rep(i,h) {
    rep(j,w) {
      cin >> M[i][j];
    }
  }
  int maxsqwidth = 0;

  rep(i,h) {
    dp[i][0] = 1 ^ M[i][0];
    maxsqwidth = max(maxsqwidth, dp[i][0]);
  }
  rep(j,w) {
    dp[0][j] = 1 ^ M[0][j];
    maxsqwidth = max(maxsqwidth, dp[0][j]);
  }

  rep2(i,1,h) {
    rep2(j,1,w) {
      if (M[i][j]) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
        maxsqwidth = max(maxsqwidth, dp[i][j]);
      }
    }
  }
  cout << maxsqwidth * maxsqwidth << endl;

  return 0;
}
