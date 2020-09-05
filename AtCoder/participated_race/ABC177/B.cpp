
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
  string s, t;
  cin >> s >> t;

  // 最長マッチしている箇所を見つけ、マッチしていない文字数を答える
  int maxmatch = 0;
  const auto difflen = (int)(s.size() - t.size());
  for (int i = 0; i <= difflen; ++i) {
    int tmpmatch = 0;
    rep(j,t.size()) {
      if (s[i+j] == t[j]) tmpmatch++;
    }
    if (maxmatch < tmpmatch) {
      maxmatch = tmpmatch;
    }
  }

  ll ans = t.size() - maxmatch;
  cout << ans << endl;
  return 0;
}
