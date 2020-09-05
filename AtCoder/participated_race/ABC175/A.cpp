
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

int main(){
  string s;
  cin >> s;

  int ans = 0;
  if (s == "SSS") {
    ans = 0;
  } else if (s == "RSS") {
    ans = 1;
  } else if (s == "SRS") {
    ans = 1;
  } else if (s == "RRS") {
    ans = 2;
  } else if (s == "SSR") {
    ans = 1;
  } else if (s == "RSR") {
    ans = 1;
  } else if (s == "SRR") {
    ans = 2;
  } else if (s == "RRR") {
    ans = 3;
  }

  cout << ans << endl;
  return 0;
}
