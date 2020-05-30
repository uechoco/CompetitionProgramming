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

// ITP1_6_C:   Official House
int main(){
  int n, b, f, r, v;
  cin >> n;
  VECTOR_DIM3(int, data, 4, 3, 10, 0) // 4棟、3階、10部屋
  for (int i = 0; i < n; ++i) {
    // b棟f階のr番目の部屋にv人が追加で入居した
    cin >> b >> f >> r >> v;
    data[b-1][f-1][r-1] += v;
  }
  REP(int, b, 0, 4) {
    if (b > 0) {
      cout << "####################" << endl;
    }
    REP(int, f, 0, 3) {
      REP(int, r, 0, 10) {
        cout << " " << data[b][f][r];
      }
      cout << endl;
    }
  }
  return 0;
}
