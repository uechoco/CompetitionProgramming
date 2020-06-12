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


// AGC010A - Addition
int main(){
  int N, a; // 2 <= N <= 1e5
  cin >> N;
  int even = 0, odd = 0; // 偶数、奇数
  rep(i, N) {
    cin >> a;
    if (a % 2 == 0) {
      ++even;
    } else {
      ++odd;
    }
  }
  bool can = true;
  if (odd % 2 == 1) {
    // 奇数がき数個あると不可能
    can = false;
  } else {
    even += odd / 2;
  }

  cout << (can ? "YES" : "NO") << endl;
  return 0;
}

