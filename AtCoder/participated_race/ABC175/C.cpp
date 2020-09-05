
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
  ll x, k, d;
  cin >> x >> k >> d;
  x = abs(x);

  // 0または0の前後で収束
  // 2回でもとの値

  ll ans = 0;

  const ll goingtozero = x / d;
  if (goingtozero >= k) {
  // 0に近づいている途中で回数切れ
    ans = x - k * d;
    //cout << "0に近づいている途中で回数切れ" << endl;
  } else {
    k -= goingtozero;
    x -= goingtozero*d;

    //cout << "x:" << x << ",k:" << k << ",going:" << goingtozero << endl;

    if (k % 2 == 0) {
      ans = x;
    } else {
      ans = abs(x-d);
    }
  }

  cout << ans << endl;
  return 0;
}
