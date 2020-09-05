
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

// ABC109 C - Skip
int main(){
  ll n, x; // 1e5, 1e9
  cin >> n >> x;
  vector<ll> xn(n + 1, 0);
  rep(i,n) cin >> xn[i];
  xn[n] = x;

  sort(xn.begin(), xn.end());

  set<ll> diffset;
  {
    ll base = xn[0];
    rep2(i,1,n+1) {
      const auto diff = xn[i] - base;
      //cout << "diff: " << diff << endl;
      diffset.emplace(diff);
      base = xn[i];
    }
  }

  /*
  cout << "diffset:";
  for (const auto& elem : diffset) {
    cout << elem << ",";
  }
  cout << endl;
  */

  // diffsetの最大公約数が答え
  ll ans = -1;
  for (const auto& elem : diffset) {
    if (ans == -1) {
      ans = elem;
    } else {
      //cout << "gcd(" << ans << "," <<  elem << ")" << endl;
      ans = greatestCommonDivisor<ll>(ans, elem);
    }
    //cout << "ans=" << ans << endl;
  }

  cout << ans << endl;

  return 0;
}
