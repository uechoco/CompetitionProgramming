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


// ABC088C - Takahashi's Information
int main(){
  VECTOR_DIM2(int, c, 3, 3, 0);
  int check = 0;
  rep(i,3) {
    rep(j,3) {
      cin >> c[i][j];
      check += c[i][j];
    }
  }
  // 全部の数字の合計は、3(a1+..+b3)なので3の倍数の必要がある
  if (check % 3 != 0) {
    cout << "No" << endl;
    return 0;
  }

  // sum = a1 + a2 + a3 + b1 + b2 + b3
  const int sum = check / 3;
  const int c11 = c[0][0];
  for (int a1 = 0; a1 <= c11; ++a1) {
    const int b1 = c11 - a1;
    const int b1b2b3 = c[0][0] + c[0][1] + c[0][2] - 3 * a1;
    const int rowa2 = c[1][0] + c[1][1] + c[1][2];
    if ((rowa2 >= b1b2b3) && ((rowa2 - b1b2b3) % 3 != 0)) {
      continue;
    }
    const int a2 = (rowa2 - b1b2b3) / 3;
    const int rowa3 = c[2][0] + c[2][1] + c[2][2];
    if ((rowa3 >= b1b2b3) && ((rowa3 - b1b2b3) % 3 != 0)) {
      continue;
    }
    const int a3 = (rowa3 - b1b2b3) / 3;
    // ここまででa1,a2,a3,b1が確定
    const int a1a2a3 = a1 + a2 + a3;
    const int rowb1 = c[0][0] + c[1][0] + c[2][0];
    if ((rowb1 >= a1a2a3) && ((rowb1 - a1a2a3) % 3 != 0)) {
      continue;
    }
    if ((rowb1 - a1a2a3) / 3 != b1) {
      continue;
    }
    const int rowb2 = c[0][1] + c[1][1] + c[2][1];
    if ((rowb2 >= a1a2a3) && ((rowb2 - a1a2a3) % 3 != 0)) {
      continue;
    }
    const int b2 = (rowb2 - a1a2a3) / 3;
    const int rowb3 = c[0][2] + c[1][2] + c[2][2];
    if ((rowb3 >= a1a2a3) && ((rowb3 - a1a2a3) % 3 != 0)) {
      continue;
    }
    const int b3 = (rowb3 - a1a2a3) / 3;
    if (sum == (a1a2a3 + b1b2b3)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
