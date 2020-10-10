
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
  VECTOR_DIM2(int, futon, h+1,w+1, 0);
  rep(i,h) {
    string s;
    cin >> s;
    rep(j,w) {
      futon[i][j] = (s[j] == '#') ? 1 : 0;
    }
  }
  rep(i,h) futon[i][w] = 1;
  rep(j,w) futon[h][j] = 1;

  ll ans = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (futon[i][j] == 0) {
        if (futon[i][j+1] == 0) {
          ++ans;
        }
        if (futon[i+1][j] == 0) {
          ++ans;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
