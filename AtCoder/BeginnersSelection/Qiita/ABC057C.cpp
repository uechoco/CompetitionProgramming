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

// 10進数の桁数を求める
int digitsNum(int64_t n) {
  int digit = 0;
  while (n > 0) {
    n /= 10;
    ++digit;
  }
  return digit;
}

// ABC057C - Digits in Multiplication
int main(){
  int64_t N; // 1 <= N <= 1e10
  cin >> N;

  // F(A, B) = 10進数で桁数の大きい方の桁数
  // n^2 <= N
  int minF = INT_MAX;
  for (int64_t i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      const int f =max(digitsNum(i), digitsNum(N/i));
      if (f < minF) {
        minF = f;
      }
    }
  }

  cout << minF << endl;
  return 0;
}
