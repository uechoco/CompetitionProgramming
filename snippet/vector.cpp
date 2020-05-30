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

int main(){

  std::vector<int> a(10, 0);
  // vectorの昇順ソート
  std::sort(a.begin(), a.end());
  // vectorの降順ソート
  std::sort(a.begin(), a.end(), std::greater<int>());


  return 0;
}
