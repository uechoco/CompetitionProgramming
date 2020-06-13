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


// ARC096A - Half and Half
int main(){
  int a, b, c, x, y; // A=A円, B=B円, AB=C円
  cin >> a >> b >> c >> x >> y;

  const int MAX_NUM = 1e5;

  int minP = INT_MAX;
  for (int ci = 0; ci <= 2 * MAX_NUM; ci += 2) {
    int p = ci * c;
    int rx = x - ci / 2;
    int ry = y - ci / 2;
    if (rx > 0) {
      p += rx * a;
    }
    if (ry > 0) {
      p += ry * b;
    }
    if (p < minP) {
      minP = p;
    }
  }

  cout << minP << endl;
  return 0;
}
