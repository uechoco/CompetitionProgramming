
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
  int n, q;
  cin >> n;
  vector<int> S(n, 0);
  rep(i,n) cin >> S[i];
  cin >> q;
  vector<int> T(q, 0);
  rep(i,q) cin >> T[i];

  sort(S.begin(), S.end());
  sort(T.begin(), T.end());

  int ans = 0;
  for (const int& t: T) {
    auto itr = std::lower_bound(S.cbegin(), S.cend(), t);
    if (*itr == t) {
      ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
