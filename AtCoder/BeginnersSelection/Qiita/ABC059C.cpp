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


// ABC059C - Sequence
int main(){
  int n; // 2 <= n <= 1e5
  cin >> n;
  vector<int64_t> a(n+10, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  // a_1を与えられた正負のどちらかの符号に決めて、
  // 残りを計算する
  ll sum1 = 0, sum2 = 0;
  ll ans1 = 0, ans2 = 0;
  rep(i, n) {
    sum1 += a[i];
    sum2 += a[i];
    if (i % 2 == 0) {
      if (sum1 <= 0) {
        ans1 += 1 - sum1;
        sum1 = 1;
      }
      if (sum2 >= 0) {
        ans2 += sum2 - (-1);
        sum2 = -1;
      }
    } else {
      if (sum1 >= 0) {
        ans1 += sum1 - (-1);
        sum1 = -1;
      }
      if (sum2 <= 0) {
        ans2 += 1 - sum2;
        sum2 = 1;
      }

    }
  }

  cout << min(ans1, ans2) << endl;
  return 0;
}

