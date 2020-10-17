
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
  int h, w;
  cin >> h >> w;

  VECTOR_DIM2(int, field, h, w, 0);
  VECTOR_DIM2(int, visited, h, w, 0);
  using Point = pair<int,int>;
  stack<Point> stk;

  rep(i,h) {
    string s;
    cin >> s;
    rep(j,w) {
      field[i][j] = s[j];
      switch (s[j]) {
        case '#':
          visited[i][j] = 2;
          break;
        case 's':
          stk.push(std::move(Point(i,j)));
          break;
      }
    }
  }

  const auto checkAndPush = [&field, &visited, &stk, &h, &w](const int ni, const int nj) {
    if (ni < 0 || ni >= h) return;
    if (nj < 0 || nj >= w) return;
    if (visited[ni][nj]) return;
    if (field[ni][nj] == '#') return;

    stk.push(std::move(Point(ni, nj)));
  };

  bool ans = false;
  while (!stk.empty()) {
    Point& p = stk.top(); // copy
    const int ci = p.first;
    const int cj = p.second;
    stk.pop();
    if (field[ci][cj] == 'g') {
      ans = true;
      break;
    }
    visited[ci][cj] = 1;
    //cout << "visited: " << DUMP(ci) << DUMP(cj) << endl;

    checkAndPush(ci-1,cj);
    checkAndPush(ci,cj-1);
    checkAndPush(ci+1,cj);
    checkAndPush(ci,cj+1);
  }

  cout << (ans ? "Yes" : "No") << endl;

  return 0;
}
