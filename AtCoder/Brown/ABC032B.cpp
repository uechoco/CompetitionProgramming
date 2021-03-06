
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
  string s; // length <= 300
  cin >> s;
  int k;
  cin >> k;

  const int sl = (int)s.length();
  if (sl < k) {
    cout << 0 << endl;
    return 0;
  } else if (sl == k) {
    cout << 1 << endl;
    return 0;
  }

  unordered_set<string> sset;
  for (int i = 0; i + k <= sl; ++i) {
    const auto sub = s.substr(i, k);
    //cout << "i:" << i << ",sub=" << sub << endl;
    sset.emplace(s.substr(i, k));
  }
  cout << sset.size() << endl;

  return 0;
}
