
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

// ARC029 A - 高橋君とお肉
int main(){
  int n;
  cin >> n;
  vector<int> t(n,0);
  rep(i, n) {
    cin >> t[i];
  }
  // nが1-4までと少ないのでbit全探索してしまう
  int ans = INT_MAX;
  for (int bit = 0; bit <= (1 << 3); ++bit) {
    int left = 0, right = 0;
    rep(i,n) {
      if ((bit>>i)&1) {
        left += t[i];
      } else {
        right += t[i];
      }
    }
    int total = max(left, right);
    if (ans > total) {
      ans = total;
    }
  }
  cout << ans << endl;
  return 0;
}
