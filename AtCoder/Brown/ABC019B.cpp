
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
  string s, sc;
  cin >> s;
  const auto slen = s.size();
  char cur = 0;
  int count = 0;
  rep(i, slen) {
    if (cur == 0) {
      cur = s[i];
      count = 1;
    } else if (cur == s[i]) {
      ++count;
    } else {
      sc += cur;
      sc += to_string(count);
      cur = s[i];
      count = 1;
    }
  }
  if (count > 0) {
    sc += cur;
    sc += to_string(count);
  }
  cout << sc << endl;

  return 0;
}
