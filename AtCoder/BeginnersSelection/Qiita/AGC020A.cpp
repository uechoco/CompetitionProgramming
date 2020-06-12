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


// AGC020A - Move and Win
int main(){
  int N, A, B; // 2 <= N <= 100, 1 <= A < B <= N <= 100
  cin >> N >> A >> B;
  const int firstA = A, firstB = B;

  int diff = B - A;
  if (diff % 2 == 0) {
    // 差が偶数の場合は、Alice
    cout << "Alice" << endl;
  } else if (diff % 2 == 1) {
    // 差が奇数の場合は、Borys
    cout << "Borys" << endl;
  }
  return 0;
}

