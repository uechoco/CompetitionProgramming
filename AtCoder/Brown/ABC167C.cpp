
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

// ABC167 C - Skill Up
int main(){
  ll n, m, x;
  cin >> n >> m >> x;
  vector<ll> c(n, 0);
  VECTOR_DIM2(ll, a, n, m, 0);
  rep(i, n) {
    cin >> c[i];
    rep(j,m) {
      cin >> a[i][j];
    }
  }

  ll minCost = LONG_LONG_MAX;
  for (int buymap = 0; buymap <= (1 << n); ++buymap) {
    ll cost = 0;
    vector<ll> rikaido(m, 0);
    for (int i = 1; i <= n; ++i) {
      if ((buymap & (1 << (i-1))) > 0) {
        cost += c[i-1];
        rep(j, m) {
          rikaido[j] += a[i-1][j];
        }
      }
    }
    if (std::all_of(rikaido.cbegin(), rikaido.cend(), [&x](const ll& r)->bool{ return r >= x; })) {
      if (minCost > cost) {
        minCost = cost;
      }
    }
  }
  cout << ((minCost == LONG_LONG_MAX) ? -1 : minCost) << endl;
  return 0;
}
