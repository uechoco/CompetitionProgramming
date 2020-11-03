
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define rep(i, N) for (int i = 0; i < (int)(N); ++i)
#define rep2(i, startValue, N) for (int i = (int)(startValue); i < (int)(N); ++i)
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
  int n, x, y;
  cin >> n;
  vector<pair<int,int>> pos;
  rep(i,n) {
    cin >> x >> y;
    pos.emplace_back(x, y);
  }

  bool ans = false;
  rep(i,n) {
    rep(j,n) {
      if (i == j) continue;
      rep(k,n) {
        if (i == k || j == k) continue;
        const int dx1 = pos[j].first - pos[i].first;
        const int dx2 = pos[k].first - pos[i].first;
        const int dy1 = pos[j].second - pos[i].second;
        const int dy2 = pos[k].second - pos[i].second;
        if (dx2 * dy1 == dx1 * dy2) {
          ans = true;
          break;
        }
      }
    }
  }

  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
