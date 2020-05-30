
#include <bits/stdc++.h>
using namespace std;

// syntax sugar: `for (int i = 0; i < N; ++i)`
#define REP(T, name, beginValue, endCondValue) \
  for (T name = beginValue; name < endCondValue; ++name)

// syntax sugar: 多次元vector
#define VECTOR_DIM3(T, name, d1, d2, d3, initValue) \
    std::vector<std::vector<std::vector<T>>> name(d1, std::vector<std::vector<T>>(d2, std::vector<int>(d3, initValue)));
#define VECTOR_DIM2(T, name, d1, d2, initValue) \
    std::vector<std::vector<T>> name(d1, std::vector<T>(d2, initValue));
#define VECTOR_DIM1(T, name, d1, initValue) \
    std::vector<T> name(d1, initValue);

// ITP1_7_C:   Spreadsheet
int main(){
  int r, c;
  cin >> r >> c;
  VECTOR_DIM2(int, data, r, c, 0) // 表の行数rと列数c、r × c の要素を持つ表
  REP(int, i, 0, r) {
    REP(int, j, 0, c) {
      cin >> data[i][j];
    }
  }

  VECTOR_DIM1(int, colTotals, c+1, 0);
  REP(int, i, 0, r + 1) {
    int rowTotal = 0;
    if (i < r) {
      REP(int, j, 0, c + 1) {
        if (j < c) {
          rowTotal += data[i][j];
          colTotals[j] += data[i][j];
          cout << data[i][j] << " ";
        } else {
          colTotals[j] += rowTotal;
          cout << rowTotal << endl;
        }
      }
    } else {
      int rowTotal = 0;
      REP(int, j, 0, c + 1) {
        if (j < c) {
          rowTotal += colTotals[j];
          cout << colTotals[j] << " ";
        } else {
          cout << rowTotal << endl;
        }
      }
    }
  }

  return 0;
}
