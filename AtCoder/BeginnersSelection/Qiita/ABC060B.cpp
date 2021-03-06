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


// ABC060B - Choose Integers
int main(){
  int A, B, C; // 100
  cin >> A >> B >> C;

  // total = (n + m + ...)A = xB + C が成立できるか
  // (xB + C) % A == 0
  bool can = false;
  for (int i = 0; i <= 100; ++i) {
    if ((i * B + C) % A == 0) {
      can = true;
      break;
    }
  }


  cout << (can ? "YES" : "NO") << endl;
  return 0;
}

