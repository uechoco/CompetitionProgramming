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


// ABC079C - Train Ticket
int main(){
  int n;
  cin >> n;
  int a = n / 1000;
  int b = (n - a * 1000) / 100;
  int c = (n - a * 1000 - b * 100) / 10;
  int d = n % 10;
  for (int i = 0; i < 8; ++i) {
    int total = a;
    if ((i & 0b100) > 0) {
      total += b;
    } else {
      total -= b;
    }
    if ((i & 0b010) > 0) {
      total += c;
    } else {
      total -= c;
    }
    if ((i & 0b001) > 0) {
      total += d;
    } else {
      total -= d;
    }
    if (total == 7) {
      cout << a;
      cout << (((i & 0b100) > 0) ? "+" : "-");
      cout << b;
      cout << (((i & 0b010) > 0) ? "+" : "-");
      cout << c;
      cout << (((i & 0b001) > 0) ? "+" : "-");
      cout << d << "=7" << endl;
      return 0;
    }
  }
  return 0;
}

