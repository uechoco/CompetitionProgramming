
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

// ABC010 C - 浮気調査
int main(){
  int txa, tya, txb, tyb, t, v;
  cin >> txa >> tya >> txb >> tyb >> t >> v;
  int n;
  cin >> n;
  vector<int> x(n,0), y(n,0);
  rep(i,n) {
    cin >> x[i] >> y[i];
  }

  rep(i,n) {
    const int xi = x[i], yi = y[i];
    const int dasq = (xi - txa)*(xi - txa)+(yi-tya)*(yi-tya);
    const int dbsq = (xi - txb)*(xi - txb)+(yi-tyb)*(yi-tyb);
    if (t*v >= sqrtl(dasq) + sqrtl(dbsq)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
