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

// ARC080 C - 4-adjacent
int main(){
  int n;
  cin >> n;
  vector<ll> a(n,0);
  int cnt4 = 0;
  int cnt2 = 0;
  rep(i, n) {
    cin >> a[i];
    if (a[i] % 4 == 0) {
      ++cnt4;
    } else if (a[i] % 2 == 0) {
      ++cnt2;
    }
  }

  if (cnt4 >= n / 2) {
    cout << "Yes" << endl;
    return 0;
  } else if (cnt4 * 2 + cnt2 >= n) {
    cout << "Yes" << endl;
    return 0;
  } else {
    cout << "No" << endl;
    return 0;
  }

  return 0;
}
