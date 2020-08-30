
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
  int n, k;
  cin >> n >> k;
  vector<int> w(n, 0);
  rep(i,n) cin >> w[i];

  ll ans = 0;
  {
    // Pを決めたときの運べる荷物の量
    const auto calc = [&w, &k, &n](const ll p) -> ll {
      int i = 0;
      for (int j = 0; j < k; ++j) { // k台のトラックしかない
        ll tmp = 0;
        while (tmp + w[i] <= p) {
          tmp += w[i];
          ++i;
          if (i == n) return n;
        }
      }
      return i;
    };

    ll mid;
    ll left = 0;
    ll right = 100000 * 10000; // MAX(n) x MAX(wi)
    while (right - left > 1) {
      mid = (left + right) / 2; // 仮のP
      const ll v = calc(mid);
      //cout << DUMP(left) << DUMP(right) << DUMP(mid) << DUMP(v) << endl;
      if (v >= n) {
        right = mid;
      } else {
        left = mid;
      }
    }
    ans = right;
  }

  cout << ans << endl;
  return 0;
}
