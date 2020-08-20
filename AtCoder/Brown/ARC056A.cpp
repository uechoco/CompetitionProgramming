
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


// ARC056 A - みんなでワイワイみかん
int main(){
  ll a, b, k, l;
  cin >> a >> b >> k >> l; // <= 1e9

  // B <= A * L なので、セットの値段のほうがお得

  // セットのみで買った場合のセット数
  ll setNumOnlySet = (k / l + ((k % l > 0) ? 1 : 0));
  ll minPrice = setNumOnlySet * b;

  for (ll setNum = setNumOnlySet; setNum >= 0; --setNum) {
    const ll setMikan = setNum * l;
    const ll fusokuMikan = (setMikan >= k ? 0 : k - setMikan);
    const ll price = setNum * b + fusokuMikan * a;
    if (price < minPrice) {
      minPrice = price;
    }
  }

  cout << minPrice << endl;
  return 0;
}
