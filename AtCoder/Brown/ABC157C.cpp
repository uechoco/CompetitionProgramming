
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

// ABC157 C - Guess The Number
int main(){
  int n, m; // 1 <= N <= 3, 0 <= M <= 5
  cin >> n >> m;

  vector<int> digits(n, 0);
  unordered_map<int, int> inputs; // s, c

  bool canCreate = true;
  rep(i,m) {
    int s, c;
    cin >> s >> c;
    const auto itr = inputs.find(s);
    if (n != 1 && s == 1 && c == 0) {
      canCreate = false; // 左から1桁が0はNG
    }
    if (itr != inputs.end() && itr->second != c) {
      canCreate = false; // 同じ桁に異なる数値
    }
    inputs[s] = c;
    digits[s-1] = c;
  }
  if (!canCreate) {
    cout << -1 << endl;
    return 0;
  }
  if (n >= 2 && digits[0] == 0) {
    digits[0] = 1;
  }
  rep(i,n) {
    cout << digits[i];
  }
  cout << endl;

  return 0;
}
