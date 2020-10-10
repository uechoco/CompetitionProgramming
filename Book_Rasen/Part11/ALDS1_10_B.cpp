
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
  int n;
  cin >> n;

  vector<int> p(n+1);
  for(int i = 1; i <= n; ++i) {
    cin >> p[i-1] >> p[i];
  }

  VECTOR_DIM2(int, m, n+2, n+2, 0);
  // m[i][j] = 0

  for (int l = 2; l <= n; ++l) {
    for(int i = 1; i <= n - l + 1; ++i) {
      int j = i + l - 1;
      m[i][j] = INT_MAX;
      for (int k = i; k <= j - 1; ++k) {
        m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]);
      }
    }
  }
  cout << m[1][n] << endl;

  return 0;
}
