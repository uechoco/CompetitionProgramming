
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

// 最大公約数
template <typename T>
T greatestCommonDivisor(T m, T n) {
  return m == 0 ? std::abs(n)
	: n == 0 ? std::abs(m)
	: greatestCommonDivisor(n, m % n);
}

// 最小公倍数
template <typename T>
T leastCommonMultiple(T m, T n) {
  return (m != 0 && n != 0)
	? (std::abs(m) / greatestCommonDivisor(m, n)) * std::abs(n)
	: 0;
}

// ABC131 C - Anti-Division
int main(){
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  const ll am = a - 1;

  const ll lcm_cd = leastCommonMultiple(c,d);

  const ll tob = b - b / c - b / d + b / lcm_cd;
  const ll fromam = am - am / c - am / d + am / lcm_cd;

  const ll ans = tob - fromam;
  cout << ans << endl;

  return 0;
}
