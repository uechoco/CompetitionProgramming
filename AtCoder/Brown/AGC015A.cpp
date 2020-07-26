
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

// AtCoder Grand Contest 015
// A - A+...+B Problem
int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  if (a > b) {
    cout << 0 << endl;
    return 0;
  }
  else if (n <= 1) {
    if (a == b) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }
  cout << ((n-2) * (b-a) + 1) << endl;
  return 0;
}
