
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


int main(){
  int n, a;
  cin >> n;
  unordered_map<int, int> amap; // 数値, 個数
  ll total = 0;
  rep(i, n) {
    cin >> a;
    amap[a]++;
    total += a;
  }
  int q, b, c;
  cin >> q;
  vector<ll> ret;
  rep(i,q) {
    cin >> b >> c;
    if (amap.find(b) != amap.end()) {
      int num = amap[b];
      if (num > 0) {
        total += (c-b) * num;
        amap[c] += amap[b];
        amap[b] = 0;
      }
    }
    ret.push_back(total);
  }

  // 答え
  rep(i,q) {
    cout << ret[i] << endl;
  }

  return 0;
}
