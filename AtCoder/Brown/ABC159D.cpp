
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


// ABC159 D - Banned K
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n,0);
  unordered_map<ll, ll> nummap; // 数値->個数
  rep(i,n) {
    cin >> a[i];
    nummap[a[i]]++;
  }

  // 計算が不要な要素を除去する
  for(auto itr = nummap.begin(); itr != nummap.end();) {
    if (itr->second <= 1) {
      itr = nummap.erase(itr);
    } else {
      ++itr;
    }
  }

  // 全通りを1回計算しておく
  ll maxtotal = 0;
  {
    for(const auto& p:nummap) {
      const ll num = p.second;
      maxtotal += num * (num-1) / 2;
    }
  }

  unordered_map<ll, ll> cache; // 数値 -> 結果

  rep(i,n) {
    const ll target = a[i];
    const auto itr = cache.find(target);
    ll total = 0;
    if (itr == cache.end()) {
      total = maxtotal;
      const ll num = nummap[target];
      total -= num * (num-1) / 2;
      if (num >= 2) {
        total += (num-1) * (num-2) / 2;
      }
      cache[target] = total;
    } else {
      total = cache[target];
    }
    cout << total << endl;
  }
  return 0;
}
