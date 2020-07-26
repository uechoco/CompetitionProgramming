
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


// ABC107 B - Grid Compression
int main(){
  int h, w; // <=100
  cin >> h >> w;
  VECTOR_DIM2(bool, grid, h, w, false);
  rep(i,h) {
    string s;
    cin >> s;
    rep(j,w) {
      if (s[j] == '#') {
        grid[i][j] = true;
      }
    }
  }
  vector<bool> hValid(h, true), wValid(w, true);
  rep(i, h) {
    bool hasBlack = false;
    rep(j,w) {
      if (grid[i][j] == true) {
        hasBlack = true;
        break;
      }
    }
    if (!hasBlack) {
      hValid[i] = false;
    }
  }
  rep(j, w) {
    bool hasBlack = false;
    rep(i,h) {
      if (grid[i][j] == true) {
        hasBlack = true;
        break;
      }
    }
    if (!hasBlack) {
      wValid[j] = false;
    }
  }
  rep (i, h) {
    if (!hValid[i]) {
      continue;
    }
    rep(j, w) {
      if (!wValid[j]) {
        continue;
      }
      cout << (grid[i][j] ? '#' : '.');
    }
    cout << endl;
  }

  return 0;
}
