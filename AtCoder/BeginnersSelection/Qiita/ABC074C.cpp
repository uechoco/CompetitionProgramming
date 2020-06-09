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


// ABC074C - Sugar Water
int main(){
  int A, B, C, D, E, F;
  // 1 <= A < B <= 30
  // 1 <= C < D <= 30
  // 1 <= E <= 100
  // 100A <= F <= 3000
  cin >> A >> B >> C >> D >> E >> F;

  vector<int> waterList;
  vector<int> sugerList;
  waterList.reserve(F);
  sugerList.reserve(F);
  for (int i = 0; i <= F; ++i) {
    for (int j = 0; j <= F; ++j) {
      int x = 100 * (A * i + B * j);
      if (x <= F) {
        waterList.push_back(x);
      }
      int y = C * i + D * j;
      if (y <= F) {
        sugerList.push_back(y);
      }
    }
  }
  int maxWater = 0;
  int maxSuger = 0;
  long double maxNoudo = -1;
  rep(i, waterList.size()) {
    const int x = waterList[i];
    rep(j, sugerList.size()) {
      const int y = sugerList[j];
      if (x + y > F) {
        continue;
      }
      if (x / 100 * E < y) {
        continue;
      }
      if (x == 0 && y == 0) {
        continue;
      }
      //cout << "x:" << x << ",y:" << y << endl;
      const long double noudo = 100 * y / (long double)(x + y);
      if (noudo >= maxNoudo) {
        maxWater = x;
        maxSuger = y;
        maxNoudo = noudo;
      }
    }
  }

  cout << (maxWater + maxSuger) << " " << maxSuger << endl;
  return 0;
}
