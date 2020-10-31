
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
  int N, W;
  cin >> N >> W;
  vector<int> values(N+1,0), weights(N+1,0);
  rep2(i,1,N+1) {
    cin >> values[i] >> weights[i];
  }
  VECTOR_DIM2(int, C, N+1, W+1, 0);

  // C[N+1][W+1]: C[i][j]を、i番目の品物の範囲内において、容量Wを超えない範囲で価値の合計の最大値
  rep2(i,1,N+1) {
    rep2(j,1,W+1) {
      C[i][j] = C[i-1][j];
      if (j-weights[i] >= 0) {
        C[i][j] = max(C[i][j], C[i-1][j-weights[i]]+values[i]);
      }
    }
  }

  cout << C[N][W] << endl;

  return 0;
}
