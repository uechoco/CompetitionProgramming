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


// ABC096C - Grid Repainting 2
int main(){
  int H, W;
  cin >> H >> W;
  VECTOR_DIM2(char, d, H, W, 0);
  VECTOR_DIM2(char, can, H, W, 0);
  rep(i, H) {
    string s;
    cin >> s;
    rep (j, W) {
      d[i][j] = s[j];
    }
  }
  rep(i, H) {
    rep(j, W) {
      if (d[i][j] != '#') {
        continue;
      }
      if (can[i][j]) {
        continue;
      }
      if (i - 1 >= 0 && i + 1 <= H - 1) {
        if (d[i+1][j] == '#') {
          can[i][j] = true;
          can[i+1][j] = true;
        }
        if (d[i-1][j] == '#') {
          can[i][j] = true;
          can[i-1][j] = true;
        }
      }
      if (j - 1 >= 0 && j + 1 <= W - 1) {
        if (d[i][j-1] == '#') {
          can[i][j] = true;
          can[i][j-1] = true;
        }
        if (d[i][j+1] == '#') {
          can[i][j] = true;
          can[i][j+1] = true;
        }
      }
      if (i - 2 >= 0 && d[i-1][j] == '#') {
          can[i][j] = true;
          can[i-1][j] = true;
      }
      if (i + 2 <= H - 1 && d[i+1][j] == '#') {
          can[i][j] = true;
          can[i+1][j] = true;
      }
      if (j - 2 >= 0 && d[i][j-1] == '#') {
          can[i][j] = true;
          can[i][j-1] = true;
      }
      if (j + 2 <= W - 1 && d[i][j+1] == '#') {
          can[i][j] = true;
          can[i][j+1] = true;
      }
      if (!can[i][j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}

