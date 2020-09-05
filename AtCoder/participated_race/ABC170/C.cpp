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
  int x, n;
  cin >> x >> n;
  vector<int> pi(n, 0);
  unordered_set<int> s;
  rep(i, n) {
    cin >> pi[i];
    s.insert(pi[i]);
  }
  if (n == 0) {
    cout << x << endl;
    return 0;
  }
  int ans = INT_MAX, ab = INT_MAX;
  for(int i = 0; i<= 101; ++i) {
    if (s.find(i) == s.end()) {
      int t = abs(i - x);
      if (t < ab) {
        ans = i;
        ab = t;
      } else if (t == ab) {
        if (ans > i) {
          ans = i;
        }
      }
    }
  }


  cout << ans << endl;
  return 0;
}

