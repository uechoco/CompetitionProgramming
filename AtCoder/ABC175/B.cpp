
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
  int n;
  cin >> n;
  vector<ll> l(n+1,0);
  rep(i,n) {
    cin >> l[i+1];
  }

  int ans = 0;
  vector<ll> sides;
  sides.reserve(4);
  for(int i = 1; i <= n-2; ++i) {
    for(int j = i+1; j <= n-1; ++j) {
      if (l[i] == l[j]) continue;
      for(int k = j+1; k <= n; ++k) {
        if ((l[i] == l[k]) || (l[j] == l[k])) continue;
        //cout << "ijk:" << i << "," << j << "," << k << endl;
        sides.clear();
        sides.push_back(l[i]);
        sides.push_back(l[j]);
        sides.push_back(l[k]);
        sort(sides.begin(), sides.end(), std::greater<ll>());
        //cout << "sides:" << sides[0] << "," << sides[1] << "," << sides[2] << endl;
        if (sides[0] < sides[1] + sides[2]) {
          ++ans;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
