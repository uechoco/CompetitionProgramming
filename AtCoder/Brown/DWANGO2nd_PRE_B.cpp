
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


// 第2回 ドワンゴからの挑戦状 予選
// B - 積み鉛筆
int main(){
  ll n; // 2 <= N <= 1e5
  cin >> n;
  vector<ll> k(n-1,0); // 1 <= ki <= 1e9
  vector<ll> l(n,0);
  multimap<ll, int> indexMap; // 長さ -> index
  rep(i,n-1) {
    cin >> k[i];
    indexMap.emplace(k[i], i);
  }

  for(const auto& p : indexMap) {
    const auto length = p.first;
    const auto index = p.second;
    if (l[index] == 0 && l[index+1] == 0) {
      l[index] = length;
      l[index+1] = length;
    } else if (l[index] != 0 && l[index+1] == 0) {
      l[index+1] = length;
    } else if (l[index] == 0 && l[index+1] != 0) {
      l[index] = length;
    }
  }

  rep(i,n) {
    if (i > 0) {
      cout << " ";
    }
    cout << l[i];
  }
  cout << endl;

  return 0;
}
