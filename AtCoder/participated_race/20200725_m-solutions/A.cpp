
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


int main(){
  int n;
  cin >> n;
  int ans;
  if (n >= 1800) ans = 1;
  else if (n >= 1600) ans = 2;
  else if (n >= 1400) ans = 3;
  else if (n >= 1200) ans = 4;
  else if (n >= 1000) ans = 5;
  else if (n >= 800) ans = 6;
  else if (n >= 600) ans = 7;
  else ans = 8;

  cout << ans << endl;
  return 0;
}
