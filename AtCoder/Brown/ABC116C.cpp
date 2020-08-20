
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


// ABC116 C - Grand Garden
int main(){
  int n ;
  cin >> n;
  vector<int> h(n,0);
  rep(i, n) cin >> h[i];

  vector<int> cur(n,0);

  const auto findStartIndex = [&h,&cur,&n]() -> int {
    rep(i,n){
      if (h[i]>cur[i]) {
        return i;
      }
    }
    return -1;
  };

  int ans = 0;
  for (int i = findStartIndex(); i != -1; i = findStartIndex()) {
    ++ans;
    int baseH = cur[i];
    for (int j = i; j < n; ++j) {
      if (cur[j] == baseH && h[j] > baseH) {
        cur[j]++;
      } else {
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
